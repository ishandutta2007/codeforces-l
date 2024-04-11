import java.io.*;
import java.util.*;

public class Main {
    private static Reader in;
    private static PrintWriter out;
    
    public static void main (String [] args) throws IOException {
        in = new Reader ();
        out = new PrintWriter (System.out, true);
        int N = in.nextInt();
        int M = in.nextInt();
        long[][] grid =  new long[N + 2][M + 2];
        for (int i = 1; i <= N; i++)
          for (int j = 1; j <= M; j++)
            grid[i][j] = in.nextInt();
        
        long[][][] dp = new long[4][N + 2][M + 2];
        for (int i = 1; i <= N; i++)
          for (int j = 1; j <= M; j++)
            dp[0][i][j] = Math.max(dp[0][i - 1][j], dp[0][i][j - 1]) + grid[i][j];
        for (int i = N; i >= 1; i--)
          for (int j = 1; j <= M; j++)
            dp[1][i][j] = Math.max(dp[1][i + 1][j], dp[1][i][j - 1]) + grid[i][j];
        for (int i = 1; i <= N; i++)
          for (int j = M; j >= 1; j--)
            dp[2][i][j] = Math.max(dp[2][i - 1][j], dp[2][i][j + 1]) + grid[i][j];
        for (int i = N; i >= 1; i--)
          for (int j = M; j >= 1; j--)
            dp[3][i][j] = Math.max(dp[3][i + 1][j], dp[3][i][j + 1]) + grid[i][j];
        
        long best = 0;
        for (int i = 2; i < N; i++) {
          for (int j = 2; j < M; j++) {
            long t1 = dp[0][i][j - 1] + dp[1][i + 1][j] + dp[2][i - 1][j] + dp[3][i][j + 1];
            if (t1 > best) best = t1;
            long t2 = dp[0][i - 1][j] + dp[1][i][j - 1] + dp[2][i][j + 1] + dp[3][i + 1][j];
            if (t2 > best) best = t2;
          }
        }
        
        out.println (best);
        out.close();
        System.exit(0);
    }
    
    static class Reader {
        final private int BUFFER_SIZE = 1 << 16;
        private DataInputStream din;
        private byte [] buffer;
        private int bufferPointer, bytesRead;
        
        public Reader () {
            din = new DataInputStream (System.in);
            buffer = new byte[BUFFER_SIZE];
            bufferPointer = bytesRead = 0;
        }
        
        public Reader (String file_name) throws IOException {
            din = new DataInputStream (new FileInputStream (file_name));
            buffer = new byte[BUFFER_SIZE];
            bufferPointer = bytesRead = 0;
        }
        
        public String readLine () throws IOException {
            byte [] buf = new byte[1024];
            int cnt = 0, c;
            while ((c = read ()) != -1) {
                if (c == '\n')
                    break;
                buf[cnt++] = (byte) c;
            }
            return new String (buf, 0, cnt);
        }
        
        public int nextInt () throws IOException {
            int ret = 0;
            byte c = read ();
            while (c <= ' ')
                c = read ();
            boolean neg = (c == '-');
            if (neg)
                c = read ();
            do {
                ret = ret * 10 + c - '0';
            } while ((c = read ()) >= '0' && c <= '9');
            if (neg)
                return -ret;
            return ret;
        }
        
        public long nextLong () throws IOException {
            long ret = 0;
            byte c = read ();
            while (c <= ' ')
                c = read ();
            boolean neg = (c == '-');
            if (neg)
                c = read ();
            do {
                ret = ret * 10 + c - '0';
            } while ((c = read ()) >= '0' && c <= '9');
            if (neg)
                return -ret;
            return ret;
        }
        
        public double nextDouble () throws IOException {
            double ret = 0, div = 1;
            byte c = read ();
            while (c <= ' ')
                c = read ();
            boolean neg = (c == '-');
            if (neg)
                c = read ();
            do {
                ret = ret * 10 + c - '0';
            } while ((c = read ()) >= '0' && c <= '9');
            if (c == '.')
                while ((c = read ()) >= '0' && c <= '9')
                    ret += (c - '0') / (div *= 10);
            if (neg)
                return -ret;
            return ret;
        }
        
        private void fillBuffer () throws IOException {
            bytesRead = din.read (buffer, bufferPointer = 0, BUFFER_SIZE);
            if (bytesRead == -1)
                buffer[0] = -1;
        }
        
        private byte read () throws IOException {
            if (bufferPointer == bytesRead)
                fillBuffer ();
            return buffer[bufferPointer++];
        }
        
        public void close () throws IOException {
            if (din == null)
                return;
            din.close ();
        }
    }
}