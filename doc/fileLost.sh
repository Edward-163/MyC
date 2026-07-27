#!/bin/sh
log=""
indent=""
# 当前shell的pid
pid=$$
cmdline=""
logfile="/testout.log"

echo "-- $(date +%T.%N) -----------------start-------" >> "${logfile}"

while true
do
#    cmdline=$(cat /proc/${pid}/cmdline)
    # cmdline默认是null字符(八进制\000字符)连接,输出到logfile里面就是黏在一块,完全没有空格!!!
    cmdline=$(cat /proc/${pid}/cmdline | tr '\000' ' ')
    log="${log}${indent}(${pid}) ${cmdline}\n"
    if [ "${pid}" == "1" ]; then
            break
    fi
    # 前段输出PPid: XX
    pid=$(grep PPid /proc/${pid}/status | awk '{ print $2; }')
    indent=" ${indent}"
done

echo -en "${log}" >> "${logfile}"
# 常见于备份某二进制,给当前脚本加些定位打印,本质还是调用原始二进制
/usr/bin/XX.bak "$@"

#-- 16:30:04.603230360 -----------------start-------
#(1996295) sh /home/fsp/ls.sh 363816
# (441808) -bash
#  (441415) sshd: root@pts/3
#   (437907) sshd: root [priv]
#    (1) /usr/lib/systemd/systemd --switched-root --system --deserialize 17