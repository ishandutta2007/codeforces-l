fun main() {
    val n = readLine()!!.toInt()
    val a = readLine()!!.split(' ').map { it.toInt() }.sorted().toIntArray()
    println((a.indices step 2).sumOf { a[it + 1] - a[it] })
}