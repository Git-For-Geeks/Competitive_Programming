import java.util.*;
import java.io.*;
public class Main {
    static FastScanner cin;
    static PrintWriter cout;
 
    private static void init()throws IOException {
        cin = new FastScanner(System.in);
        cout = new PrintWriter(System.out);
    }
 
    private static void close(){
        cout.close();
    }
    static int n, m, f, k;
    static List<Integer> e[];
    static int not_have_car_sta[];
    static int h[];
    static int not_have_car[];
    static int level[];
    private static void sol()throws IOException {
        n = cin.nextInt(); m = cin.nextInt();
        e = new ArrayList[n];
        for(int i = 0; i < m; i ++ ) {
            int a = cin.nextInt(), b = cin.nextInt();
            a--; b--;
            if(e[a] == null) e[a] = new ArrayList<>();
            if(e[b] == null) e[b] = new ArrayList<>();
            e[a].add(b);
            e[b].add(a);
        }
        f = cin.nextInt();
        h = new int[f];
        not_have_car = new int[f];
        not_have_car_sta = new int[n];
        for(int i = 0; i < f; i ++ ) {
            h[i] = cin.nextInt();
            h[i]--;
        }
 
        int dp1[][] = new int[n][65];//2^6 - 1, dp1 表示有nhc
        k = cin.nextInt();
        dp1[0][0] = 1;
        for(int i = 0; i < k; i ++ ) {
            int p = cin.nextInt();
            p--;
            not_have_car_sta[h[p]] |= (1<<i);
            not_have_car[p]++;
        }
 
        /**
         * bfs 建立分层图
         */
        level = new int[n];
        for(int i = 0; i < n; i ++ ) level[i] = n+100;
        level[0] = 0;
        
        Queue<Integer> que = new ArrayDeque<>();
        que.add(0);
        while(!que.isEmpty()){
            int x = que.poll();
            for(Integer v: e[x]){
                if(level[v] == n+100){
                    level[v] = level[x] + 1;
                    que.add(v);
                }
            }
        }
        
        //遍历每条边，记录方案 O(m)
        boolean in_que[] = new boolean[n];
        que.add(0);
        in_que[0] = true;
        while(!que.isEmpty()){
            int x = que.poll();
            for(int i = (1<<k) - 1; i >= 0; i -- ) dp1[x][i|not_have_car_sta[x]] |= dp1[x][i];
            for(Integer v: e[x]){
                if(level[v] == level[x] + 1) {
//                    cout.print(v+" ");
                    if(!in_que[v]) {
                        que.add(v);
                        in_que[v] = true;
                    }
//                    dp1[v][0] = 1;
                    for(int i = (1<<k) - 1; i >= 0; i -- ) {
                        dp1[v][i] |= dp1[x][i];
                    }
                }
            }
        }
//        cout.print("\n");
 
        int dp2[] = new int[65];
        dp2[0] = 1;
        for(int i = 0; i < f; i ++ ) {
            if(not_have_car[i] == 1) continue;
            for(int j = (1<<k) - 1; j >= 0; j --) {
                for(int jj = (1<<k)-1; jj >= 0; jj--){
                    dp2[j|jj] |= (dp2[j]&dp1[h[i]][jj]);
                }
            }
           /* for(int j = (1<<k)-1; j > 0; j -- ) {
                for(int t = j; t > 0; t  = (t-1)&j){
                    dp2[j] |= (dp2[j^t] & dp1[h[i]][t]);
                }
            }*/
        }
        int ans = k;
        for(int i = (1<<k) - 1; i >= 0; i -- ) {
            if(dp2[i] > 0) ans = Math.min(ans, k - builtinCount(i));
        }
        cout.println(ans);
    }
 
    private static int builtinCount(int i) {
        int ans = 0;
        while(i > 0){
            if((i&1) == 1)ans++;
            i /= 2;
        }
        return ans;
    }
 
    public static void main(String[] args) throws IOException {
        init();
        int t = cin.nextInt();
        while(t-- > 0)sol();
        close();
    }
}
class FastScanner {
    BufferedReader br;
    StringTokenizer st = new StringTokenizer("");
 
    public FastScanner(InputStream s) {
        br = new BufferedReader(new InputStreamReader(s));
    }
 
    public FastScanner(String s) throws FileNotFoundException {
        br = new BufferedReader(new FileReader(new File(s)));
    }
 
    public String next() throws IOException {
        if (!st.hasMoreTokens())
            st = new StringTokenizer(br.readLine());
        return st.nextToken();
    }
 
    public int nextInt() throws IOException {
        return Integer.parseInt(next());
    }
 
    public long nextLong() throws IOException {
        return Long.parseLong(next());
    }
 
    public double nextDouble() throws IOException {
        return Double.parseDouble(next());
    }
}