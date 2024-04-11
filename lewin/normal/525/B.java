import java.io.*;
import java.util.*;

public class pashastring {
  private static InputReader in;
  private static PrintWriter out;

  public static void main(String[] args) throws IOException {
    in = new InputReader(System.in);
    out = new PrintWriter(System.out, true);
    char[] c = in.next().toCharArray();
    int M = c.length;
    int N = in.nextInt();
    int[] a = new int[M];
    for (int i =0 ; i < N; i++)
      a[in.nextInt()-1]++;
    
    char[] res = new char[M];
    int psum = 0;
    for (int i = 0; 2*i < M; i++) {
      int j = M-i-1;
      psum += a[i];
      if (psum % 2 == 0) {
        res[i] = c[i];
        res[j] = c[j];
      } else {
        res[i] = c[j];
        res[j] = c[i];
      }
    }
    out.println(new String(res));
    out.close();
    System.exit(0);
  }

  static class InputReader {
    public BufferedReader reader;
    public StringTokenizer tokenizer;

    public InputReader(InputStream stream) {
      reader = new BufferedReader(new InputStreamReader(stream), 32768);
      tokenizer = null;
    }

    public String next() {
      while (tokenizer == null || !tokenizer.hasMoreTokens()) {
        try {
          tokenizer = new StringTokenizer(reader.readLine());
        } catch (IOException e) {
          throw new RuntimeException(e);
        }
      }
      return tokenizer.nextToken();
    }

    public int nextInt() {
      return Integer.parseInt(next());
    }
  }


}