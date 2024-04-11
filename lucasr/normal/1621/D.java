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
		DTheWinterHike solver = new DTheWinterHike();
		int testCount = Integer.parseInt(in.next());
		for (int i = 1; i <= testCount; i++)
			solver.solve(i, in, out);
		out.close();
	}

	static class DTheWinterHike {
		public static MyScanner sc;
		public static PrintWriter out;

		public void solve(int testNumber, MyScanner sc, PrintWriter out) {
			DTheWinterHike.sc = sc;
			DTheWinterHike.out = out;
			int n = sc.nextInt();
			int[][] table = new int[2 * n][];
			for (int i = 0; i < 2 * n; i++) {
				table[i] = sc.nextIntArray(2 * n);
			}
			long ans = 0;
			for (int i = 0; i < n; i++) {
				for (int j = 0; j < n; j++) {
					ans += table[n + i][n + j];
				}
			}
			long tmp = Math.min(table[0][n], table[0][2 * n - 1]);
			tmp = Math.min(tmp, Math.min(table[n - 1][n], table[n - 1][2 * n - 1]));
			tmp = Math.min(tmp, Math.min(table[n][0], table[n][n - 1]));
			tmp = Math.min(tmp, Math.min(table[2 * n - 1][0], table[2 * n - 1][n - 1]));
			out.println(ans + tmp);
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
			int[] ret = new int[n];
			for (int i = 0; i < n; i++) {
				ret[i] = nextInt();
			}
			return ret;
		}

	}
}