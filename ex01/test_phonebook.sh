#!/bin/bash

# 自动测试 CPP00 ex01 PhoneBook

exec_name="./phonebook"

# 检查可执行文件是否存在
if [ ! -f "$exec_name" ]; then
    echo "请先编译 phonebook 可执行文件"
    exit 1
fi

# 输入模拟函数
function send_input() {
    for input in "$@"; do
        echo "$input"
    done
}

# 1️⃣ 添加 8 个联系人
{
send_input "ADD" "John" "Doe" "JD" "1234567890" "Secret1"
send_input "ADD" "Jane" "Smith" "JS" "0987654321" "Secret2"
send_input "ADD" "Alice" "Brown" "AB" "1112223333" "Secret3"
send_input "ADD" "Bob" "White" "BW" "4445556666" "Secret4"
send_input "ADD" "Charlie" "Black" "CB" "7778889999" "Secret5"
send_input "ADD" "David" "Green" "DG" "0001112222" "Secret6"
send_input "ADD" "Eve" "Blue" "EB" "3334445555" "Secret7"
send_input "ADD" "Frank" "Yellow" "FY" "6667778888" "Secret8"

# 2️⃣ 搜索每个联系人
for i in {0..7}; do
    send_input "SEARCH" "$i"
done

# 3️⃣ 测试索引越界
send_input "SEARCH" "8"  # 应提示索引不存在
send_input "SEARCH" "-1" # 应提示索引不存在
send_input "SEARCH" "abc" # 应提示无效索引

# 4️⃣ 添加第 9 个联系人，覆盖 contacts[0]
send_input "ADD" "Grace" "Pink" "GP" "9998887777" "Secret9"
send_input "SEARCH" "0" # 应显示 Grace Pink

# 5️⃣ 退出
send_input "EXIT"
} | $exec_name