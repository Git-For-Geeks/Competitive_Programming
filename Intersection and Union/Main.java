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
    static class TreeNode{
        int u, l, r, v, tag;
 
        public TreeNode(int u, int l, int r) {
            this.u = u;
            this.l = l;
            this.r = r;
        }
 
        public TreeNode() {
        }
 
        public int getU() {
            return u;
        }
 
        public void setU(int u) {
            this.u = u;
        }
 
        public int getL() {
            return l;
        }
 
        public void setL(int l) {
            this.l = l;
        }
 
        public int getR() {
            return r;
        }
 
        public void setR(int r) {
            this.r = r;
        }
 
        public int getV() {
            return v;
        }
 
        public void setV(int v) {
            this.v = v;
        }
 
        public int getTag() {
            return tag;
        }
 
        public void setTag(int tag) {
            this.tag = tag;
        }
    }
    static TreeNode tr[] = new TreeNode[(int) (3e5+10)*4];
    static void build(TreeNode[] tr, int u, int l, int r){
        if(l == r) tr[u] = new TreeNode(u,l,r);
        else {
            tr[u] = new TreeNode(u,l,r);
            int mid = l + r >> 1;
            build(tr, u*2, l, mid);
            build(tr, u*2+1,mid+1,r);
        }
    }
    /*static void pushup(TreeNode[] tr, int u){
        int ls = u*2;
        int rs = u*2+1;
        tr[u].v = tr[ls].v + tr[rs].v;
    }*/
    static void pushdown(TreeNode[] tr, int u){
        if(tr[u].tag > 0){
            int ls = u*2;
            int rs = u*2+1;
            tr[ls].v = tr[u].tag;
            tr[rs].v = tr[u].tag;
            tr[ls].tag = tr[rs].tag = tr[u].tag;
            tr[u].tag = 0;
        }
    }
    static void mody(TreeNode[] tr, int u, int l, int r, int v){
        if(l <= tr[u].l && tr[u].r <= r){
            tr[u].tag = v;
            tr[u].v = v;
        }else {
            pushdown(tr,u);
            int mid = tr[u].l + tr[u].r >> 1;
            if(l <= mid) mody(tr, u*2, l, r, v);
            if(r > mid) mody(tr, u*2+1, l, r, v);
        }
    }
    static int query(TreeNode[] tr, int u, int x){
        if(tr[u].l == x && tr[u].r == x){
            return tr[u].v;
        }else {
            pushdown(tr,u);
            int mid = tr[u].l + tr[u].r >> 1;
            if(x <= mid) return query(tr, u*2, x);
            else return query(tr, u*2+1, x);
        }
    }
    static long mod = 998244353;
    static long qpow(long a, long k, long p){
        long res = 1;
        while(k > 1) {
            if( (k&1) ==1 ) res = res*a%k;
            a = a*a%k;
            k>>=1;
        }
        return res;
    }
    private static void sol()throws IOException {
        int n = cin.nextInt();
        build(tr,1,0, (int) 3e5);
        for(int i = 0; i < n; i ++ ) {
            int l = cin.nextInt(), r = cin.nextInt();
            mody(tr,1,l,r, i+1);
        }
 
        long b2[] = new long[(int) (3e5+10)];
        long b3[] = new long[(int) (3e5+10)];
        b2[0] = b3[0] = 1;
        for(int i = 1; i <= 3e5; i ++ ) {
            b2[i] = b2[i-1] * 2 %mod;
            b3[i] = b3[i-1] * 3 %mod;
        }
        long ans = 0;
        for(int i = 0; i <= 3e5; i ++ ) {
            int cnt = query(tr,1,i);
//            if(i>=1 && i <= 9) cout.println("pos[" + i +"]=" + cnt);
            long res = 0;
            if(cnt == 0) continue;
            else if(cnt == 1) res = b2[n-1];
            else res = b3[cnt-  2]*b2[n - cnt + 1]%mod;
            ans = (res + ans)%mod;
        }
        cout.print(ans);
    }
    public static void main(String[] args) throws IOException {
        init();
        sol();
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
        while (!st.hasMoreTokens()){
            try {
                st = new StringTokenizer(br.readLine());
            } catch (IOException e) { e.printStackTrace(); }
        }
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
