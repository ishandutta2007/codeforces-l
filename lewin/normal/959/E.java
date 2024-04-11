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
*/public class Main {
	public static void main(String[] args) {
		InputStream inputStream = System.in;
		OutputStream outputStream = System.out;
		InputReader in = new InputReader(inputStream);
		OutputWriter out = new OutputWriter(outputStream);
		TaskE solver = new TaskE();
		solver.solve(1, in, out);
		out.close();
	}
static class TaskE   {
public void solve(int testNumber, InputReader in, OutputWriter out) {
        long n = in.nextLong();
        out.println(solve(n));
    }

public static long solve(long n) {
        if (n == 1) return 0;
        if ((n & (n-1)) == 0) {
            return 2 * solve(n/2) + (n/2);
        } else {
            long x = Long.highestOneBit(n-1);
            return solve(x) + solve(n - x) + x;
        }
    }

}
static class OutputWriter   {
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

}
static class InputReader   {
private InputStream stream;
private byte[] buf = new byte[1 << 16];
private int curChar;
private int numChars;

public InputReader(InputStream stream) {
        this.stream = stream;
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

public long nextLong() {
        int c;
        for (c = this.read(); isSpaceChar(c); c = this.read()) {
            ;
        }

        byte sgn = 1;
        if (c == 45) {
            sgn = -1;
            c = this.read();
        }

        long res = 0L;

        while (c >= 48 && c <= 57) {
            res *= 10L;
            res += (long) (c - 48);
            c = this.read();
            if (isSpaceChar(c)) {
                return res * (long) sgn;
            }
        }

        throw new InputMismatchException();
    }

public static boolean isSpaceChar(int c) {
        return c == 32 || c == 10 || c == 13 || c == 9 || c == -1;
    }

}
}