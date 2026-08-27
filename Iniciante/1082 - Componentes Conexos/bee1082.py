# Beecrowd 1082 - Componentes Conexos


def main():
    N = int(input())

    for _ in range(N):

        V, E = map(int, input().split())

        graph = [[0 for _ in range(V)] for _ in range(V)]

        for i in range(E):
            a, b = map(str, input().split())

            a_ord = ord(a) - 97
            b_ord = ord(b) - 97

            graph[a_ord][b_ord] = 1

        for i in range(V):
            for j in range(V):

                if graph[i][j] == 1 or i == j:
                    print(j)
        for g in graph:
            print(g)

if __name__ == "__main__":
    main()
