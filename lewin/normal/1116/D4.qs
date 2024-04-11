namespace Solution {
    open Microsoft.Quantum.Primitive;
    open Microsoft.Quantum.Canon;
    open Microsoft.Quantum.Extensions.Diagnostics;

    operation DumpUnitary (N : Int, unitary : (Qubit[] => Unit)) : Unit {
        let size = 1 <<< N;
        
        using (qs = Qubit[N]) {
            for (k in 0 .. size - 1) {                
                // Prepare k-th basis vector
                let binary = BoolArrFromPositiveInt(k, N);
                
                //Message($"{k}/{N} = {binary}");
                // binary is little-endian notation, so the second vector tried has qubit 0 in state 1 and the rest in state 0
                ApplyPauliFromBitString(PauliX, true, binary, qs);
                
                // Apply the operation
                unitary(qs);
                
                // Dump the contents of the k-th column
                DumpMachine($"DU_{N}_{k}.txt");
                
                ResetAll(qs);
            }
        }
    }

    operation XX(qs: Qubit[]) : Unit {
        let N = Length(qs);
        for (i in 0..N-2) {
             Controlled X([qs[N-1]], qs[i]);
        }
        H(qs[N-1]);
        for (i in 0..N-2) {
             Controlled X([qs[N-1]], qs[i]);
        }
    }

    operation Solve (qs : Qubit[]) : Unit {
        let N = Length(qs);
        if (N == 2) {
            XX(qs);
        } else {
            for (j in 0..N-2) {
                Controlled X([qs[N-1]], qs[j]);
            }
            for (j in 0..N-3) {
                X(qs[j]);
                for (i in j+1..N-2) {
                    Controlled X(qs[0..j], qs[i]);
                }
                X(qs[j]);
            }
            for (j in 0..N-2) {
                Controlled X([qs[N-1]], qs[j]);
            }
            XX(qs);
        }
    }

    operation Tester(N : Int) : Unit {
        DumpUnitary(N, Solve);
    }
}