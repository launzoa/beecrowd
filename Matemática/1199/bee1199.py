if __name__ == "__main__":
    fi = 0; bo = 1
    for _ in range(1505):
        print(bo)
        fi, bo = bo, (fi+bo) % 1000
       