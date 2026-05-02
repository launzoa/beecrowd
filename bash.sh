BASE_DIR="$(pwd)"

clear 

echo  "Category: "
read CATEGORY 

echo  "Number: "
read NUMBER 

echo  "Title: "
read TITLE 

if [[ -z $CATEGORY || -z $TITLE || -z $NUMBER ]]; then
    echo "Error: All fields are required."
    sleep 2
    exit 1
fi

FOLDER_NAME="${NUMBER} - ${TITLE// /_}" 
FULL_PATH="$BASE_DIR/$CATEGORY/$FOLDER_NAME"

if [ ! -d "$BASE_DIR/$CATEGORY" ]; then
    echo "Category '$CATEGORY' does not exist. Creating it..."
    mkdir -p "$BASE_DIR/$CATEGORY"
fi


mkdir -p "$FULL_PATH"
cd "$FULL_PATH" || exit 

PREFIX="bee${NUMBER}"

# C++ 
cat <<EOF > "${PREFIX}.cpp"
// Beecrowd ${NUMBER} - ${TITLE}
#include <iostream>

using namespace std;

int main() {
    
    // Sua lógica aqui
    
    return 0;
}
EOF

# Julia
cat <<EOF > "${PREFIX}.jl"
# Beecrowd ${NUMBER} - ${TITLE}

function main()
    
end

main()
EOF

# Python
cat <<EOF > "${PREFIX}.py"
# Beecrowd ${NUMBER} - ${TITLE}

def main():
    pass

if __name__ == "__main__":
    main()
EOF

touch in.txt out.txt

# Java
cat <<EOF > "${PREFIX}.java"
// Beecrowd ${NUMBER} - ${TITLE}

public class ${PREFIX} {
    public static void main(String[] args) {
        
    }
}
EOF

# C99
cat <<EOF > "${PREFIX}.c"
// Beecrowd ${NUMBER} - ${TITLE}
#include <stdio.h>

int main() {
    
    return 0;
}
EOF


echo "Structure successfully created at: $FULL_PATH"
ls -la

echo "Press Enter to continue..." 
read CONTINUE 
