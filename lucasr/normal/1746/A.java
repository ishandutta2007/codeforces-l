import java.io.OutputStream;
import java.io.IOException;
import java.io.InputStream;
import java.io.PrintWriter;
import java.util.StringTokenizer;
import java.io.IOException;
import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.io.InputStream;

/**
 * Built using CHelper plug-in
 * Actual solution is at the top
 *
 * @author lucasr
 */
public class Main {
	public static void main(String[] args) {
		InputStream inputStream = System.in;
		OutputStream outputStream = System.out;
		MyScanner in = new MyScanner(inputStream);
		PrintWriter out = new PrintWriter(outputStream);
		AMaxmina solver = new AMaxmina();
		int testCount = Integer.parseInt(in.next());
		for (int i = 1; i <= testCount; i++)
			solver.solve(i, in, out);
		out.close();
	}

	static class AMaxmina {
		public static MyScanner sc;
		public static PrintWriter out;

		public void solve(int testNumber, MyScanner sc, PrintWriter out) {
			AMaxmina.sc = sc;
			AMaxmina.out = out;
			int n = sc.nextInt();
			int k = sc.nextInt();
			int[] vals = sc.nextIntArray(n);
			boolean has = false;
			for (int i = 0; i < n; i++) {
				if (vals[i] == 1) has = true;
			}
			out.println(has ? "YES" : "NO");
		}

	}

	static class MyScanner {
		private BufferedReader br;
		private StringTokenizer tokenizer;

		public MyScanner(InputStream is) {
			br = new BufferedReader(new InputStreamReader(is));
		}

		public String next() {
			while (tokenizer == null || !tokenizer.hasMoreTokens()) {
				try {
					tokenizer = new StringTokenizer(br.readLine());
				} catch (IOException e) {
					throw new RuntimeException(e);
				}
			}
			return tokenizer.nextToken();
		}

		public int nextInt() {
			return Integer.parseInt(next());
		}

		public int[] nextIntArray(int n) {
			return nextIntArray(n, false);
		}

		public int[] nextIntArray(int n, boolean subtractOne) {
			int add = subtractOne ? -1 : 0;
			int[] ret = new int[n];
			for (int i = 0; i < n; i++) {
				ret[i] = nextInt() + add;
			}
			return ret;
		}

	}
}