import java.io.OutputStream;
import java.io.IOException;
import java.io.InputStream;
import java.io.OutputStream;
import java.io.PrintWriter;
import java.io.BufferedWriter;
import java.io.Writer;
import java.io.OutputStreamWriter;
import java.util.InputMismatchException;
import java.io.IOException;
import java.io.InputStream;

/**
 * Built using CHelper plug-in
 * Actual solution is at the top
 */
public class Main {
    public static void main(String[] args) {
        InputStream inputStream = System.in;
        OutputStream outputStream = System.out;
        InputReader in = new InputReader(inputStream);
        OutputWriter out = new OutputWriter(outputStream);
        TaskB solver = new TaskB();
        solver.solve(1, in, out);
        out.close();
    }

    static class TaskB {
        public void solve(int testNumber, InputReader in, OutputWriter out) {
            int n = in.nextInt(), k = in.nextInt(), m = in.nextInt();

            int[] arr = in.readIntArray(n);
            int[] stack = new int[2 * n];
            int[] count = new int[2 * n];
            int sidx = 0;

            int one = n;
            for (int i = 0; i < n; i++) {
                if (sidx == 0 || stack[sidx - 1] != arr[i]) {
                    stack[sidx] = arr[i];
                    count[sidx++] = 1;
                } else {
                    if (++count[sidx - 1] == k) {
                        one -= k;
                        sidx--;
                    }
                }
            }

            if (m == 1) {
                out.println(one);
                return;
            }

            if (one == 0) {
                out.println(0);
                return;
            }

            if (sidx == 1) {
                out.println(1L * m * count[0] % k);
                return;
            }

            int f = 0, b = sidx - 1;
            while (f < b && stack[f] == stack[b] && (count[f] + count[b]) % k == 0) {
                f++;
                b--;
            }
            if (f > b) {
                out.println(1L * one * (m % 2));
                return;
            }

            if (f == b) {
                long res = 1L * m * count[f] % k;
                if (res != 0) {
                    for (int i = 0; i < f; i++) {
                        res += count[i];
                    }
                    for (int i = sidx - 1; i > b; i--) {
                        res += count[i];
                    }
                    out.println(res);
                } else {
                    out.println(0);
                }
                return;
            }

            long res = 0;
            for (int i = 0; i < f; i++) {
                res += count[i];
            }
            for (int i = sidx - 1; i > b; i--) {
                res += count[i];
            }
            long base = 0;
            for (int i = f; i <= b; i++) {
                base += count[i];
            }
            long sub = (stack[f] == stack[b]) ? 1L * (count[f] + count[b]) / k * k : 0;
            res += (base - sub) * (m - 1) + base;
            out.println(res);
        }

    }

    static class OutputWriter {
        private final PrintWriter writer;

        public OutputWriter(OutputStream outputStream) {
            writer = new PrintWriter(new BufferedWriter(new OutputStreamWriter(outputStream)));
        }

        public OutputWriter(Writer writer) {
            this.writer = new PrintWriter(writer);
        }

        public void close() {
            writer.close();
        }

        public void println(long i) {
            writer.println(i);
        }

        public void println(int i) {
            writer.println(i);
        }

    }

    static class InputReader {
        private InputStream stream;
        private byte[] buf = new byte[1024];
        private int curChar;
        private int numChars;

        public InputReader(InputStream stream) {
            this.stream = stream;
        }

        public int[] readIntArray(int tokens) {
            int[] ret = new int[tokens];
            for (int i = 0; i < tokens; i++) {
                ret[i] = nextInt();
            }
            return ret;
        }

        public int read() {
            if (this.numChars == -1) {
                throw new InputMismatchException();
            } else {
                if (this.curChar >= this.numChars) {
                    this.curChar = 0;

                    try {
                        this.numChars = this.stream.read(this.buf);
                    } catch (IOException var2) {
                        throw new InputMismatchException();
                    }

                    if (this.numChars <= 0) {
                        return -1;
                    }
                }

                return this.buf[this.curChar++];
            }
        }

        public int nextInt() {
            int c;
            for (c = this.read(); isSpaceChar(c); c = this.read()) {
                ;
            }

            byte sgn = 1;
            if (c == 45) {
                sgn = -1;
                c = this.read();
            }

            int res = 0;

            while (c >= 48 && c <= 57) {
                res *= 10;
                res += c - 48;
                c = this.read();
                if (isSpaceChar(c)) {
                    return res * sgn;
                }
            }

            throw new InputMismatchException();
        }

        public static boolean isSpaceChar(int c) {
            return c == 32 || c == 10 || c == 13 || c == 9 || c == -1;
        }

    }
}