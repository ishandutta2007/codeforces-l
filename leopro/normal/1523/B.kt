fun main() {
    repeat(readLine()!!.toInt()) {
        val n = readLine()!!.toInt()
        val a = readLine()
        println(3 * n)
        for (i in 1 until n step 2){
            val j = i + 1
            println("1 $i $j")
            println("2 $i $j")
            println("2 $i $j")
            println("1 $i $j")
            println("2 $i $j")
            println("2 $i $j")
        }
    }
}