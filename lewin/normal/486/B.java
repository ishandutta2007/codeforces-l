import java.io.*;
import java.util.*;

public class ormatrix {

  private static Reader in;
  private static PrintWriter out;

  public static void main(String[] args) throws IOException {
    in = new Reader();
    out = new PrintWriter(System.out, true);
    int N = in.nextInt(), M = in.nextInt();
    int[][] arr = new int[N][M];
    for (int i = 0; i < N; i++) {
      for (int j = 0; j < M; j++) {
        arr[i][j] = in.nextInt();
      }
    }
    
    int[][] brr = new int[N][M];
    for(int i = 0; i < N; i++) {
      for (int j = 0; j < M; j++) {
        boolean ok = true;
        for (int k = 0; k < M; k++)
          if (arr[i][k] == 0) {
            ok = false;
            break;
          }
        if (!ok) break;
        for (int k = 0; k < N; k++) {
          if (arr[k][j] == 0) {
            ok = false;
            break;
          }
        }
        brr[i][j] = ok ? 1 : 0;
      }
    }
    
    boolean works = true;
    outer : for (int i = 0; i < N; i++) {
      for (int j = 0; j < M; j++) {
        boolean ok = false;
        for (int k = 0; k < M; k++) {
          if (brr[i][k] == 1) {
            ok = true;
            break;
          }
        }
        for (int k = 0; k < N; k++) {
          if (brr[k][j] == 1) {
            ok = true;
            break;
          }
        }
        
        if (ok != (arr[i][j] == 1)) {
          works = false;
          break outer;
        }
      }
    }
    
    if (!works) out.println("NO");
    else {
      out.println("YES");
      for (int i = 0; i < N; i++) {
        out.print(brr[i][0]);
        for (int j = 1; j < M; j++) {
          out.print(" " + brr[i][j]);
        }
        out.println();
      }
    }
    out.close();
    System.exit(0);
  }

  static class Reader {
    final private int BUFFER_SIZE = 1 << 16;
    private DataInputStream din;
    private byte[] buffer;
    private int bufferPointer, bytesRead;

    public Reader() {
      din = new DataInputStream(System.in);
      buffer = new byte[BUFFER_SIZE];
      bufferPointer = bytesRead = 0;
    }

    public Reader(String file_name) throws IOException {
      din = new DataInputStream(new FileInputStream(file_name));
      buffer = new byte[BUFFER_SIZE];
      bufferPointer = bytesRead = 0;
    }

    public String readLine() throws IOException {
      byte[] buf = new byte[1 << 20];
      int cnt = 0;
      byte c = read();
      while (c <= ' ')
        c = read();
      do {
        buf[cnt++] = c;
      } while ((c = read()) != '\n');
      return new String(buf, 0, cnt);
    }

    public String next() throws IOException {
      byte[] buf = new byte[1 << 20];
      int cnt = 0;
      byte c = read();
      while (c <= ' ')
        c = read();
      do {
        buf[cnt++] = c;
      } while ((c = read()) > ' ');
      return new String(buf, 0, cnt);
    }

    public int nextInt() throws IOException {
      int ret = 0;
      byte c = read();
      while (c <= ' ')
        c = read();
      boolean neg = (c == '-');
      if (neg)
        c = read();
      do {
        ret = ret * 10 + c - '0';
      } while ((c = read()) >= '0' && c <= '9');
      if (neg)
        return -ret;
      return ret;
    }

    public long nextLong() throws IOException {
      long ret = 0;
      byte c = read();
      while (c <= ' ')
        c = read();
      boolean neg = (c == '-');
      if (neg)
        c = read();
      do {
        ret = ret * 10 + c - '0';
      } while ((c = read()) >= '0' && c <= '9');
      if (neg)
        return -ret;
      return ret;
    }

    public double nextDouble() throws IOException {
      double ret = 0, div = 1;
      byte c = read();
      while (c <= ' ')
        c = read();
      boolean neg = (c == '-');
      if (neg)
        c = read();
      do {
        ret = ret * 10 + c - '0';
      } while ((c = read()) >= '0' && c <= '9');
      if (c == '.')
        while ((c = read()) >= '0' && c <= '9')
          ret += (c - '0') / (div *= 10);
      if (neg)
        return -ret;
      return ret;
    }

    private void fillBuffer() throws IOException {
      bytesRead = din.read(buffer, bufferPointer = 0, BUFFER_SIZE);
      if (bytesRead == -1)
        buffer[0] = -1;
    }

    private byte read() throws IOException {
      if (bufferPointer == bytesRead)
        fillBuffer();
      return buffer[bufferPointer++];
    }

    public void close() throws IOException {
      if (din == null)
        return;
      din.close();
    }
  }


}