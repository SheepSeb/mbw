#!/bin/bash

panicFile='paniCommands'

# Colors chosen by Volicaz
red="\033[0;31m"
resetRed="\033[0m"
green="\033[0;32m"
yellow="\033[0;33m"
turquoise="\033[0;36m"
lightMagenta="\033[1;35m"

printf "$lightMagenta"
printf "Database Integration CLI \nVersion: 0.1.0 \nUsage: \nCommands: h|help u|user p|password con|connection c|connect b|backup r|restore pk|panic exit|q|quit$resetRed\n\n"

admin_user="sebastian_sys_admin"
password_user="test"

backupFolder="~/dbBackup"

cli_name=${0##*/}

conn="mongodb+srv://mbw.jttju.mongodb.net/mbw"
while true
do
    printf "$turquoise"
    read -p "$cli_name> " args col
    printf "$resetRed"
    case $args in
        h|help)
            echo "Help"
            ;;
        u|user)
            echo "Setting user"
            if [ -z "$col" ]
            then
                echo "No user specified"
                echo "Default user: $admin_user"
            else
                admin_user=$col
                echo "User set to: $admin_user"
            fi
            ;;
        p|password)
            echo "Setting password"
            if [ -z "$col" ]; then
                echo "Password: $password_user"
            else
                password_user=$col
                echo "Password set to $password_user"
            fi
            ;;
        con|connection)  
            echo "Add the connection string"
            if [ -z  "$col" ]
            then
                echo "No connection string given"
                echo "Connection default to $conn"
            else
                conn=$col
                echo "Connection string set to $conn"
            fi
            ;;
        c|connect)
            echo "Establishing connection"
            echo "Starting MongoSH"
            echo "Connection Started"
            mongosh $conn --username $admin_user --password $password_user
            #exit
            ;;
        b|backup)
            printf "$green\n"
            echo "Backing up database"
            mongodump --uri "mongodb+srv://$admin_user:$password_user@mbw.jttju.mongodb.net" --out $backupFolder --forceTableScan
            echo "Database backed up at $backupFolder"
            printf "$resetRed"
            ;;
        r|restore)
            printf "$green\n"
            echo "Restoring database"
            mongorestore --uri "mongodb+srv://$admin_user:$password_user@mbw.jttju.mongodb.net" $backupFolder
            echo "Database restored"
            printf "$resetRed"
            ;;
        pk|panic)
            printf "$red\n"
            echo "Anomaly detected entering panic"
            echo "Panic mode activated"
            mongo $conn --username $admin_user --password $password_user --eval "db.getSiblingDB('mbw').dropDatabase()"
            mongorestore --uri "mongodb+srv://$admin_user:$password_user@mbw.jttju.mongodb.net" $backupFolder
            echo "Panic mode deactivated"
            printf "$resetRed"
            ;;
        exit|q|quit)
            echo "Exiting Bye"
            exit;;
        *)
            echo "Invalid command"
            ;;
    esac
done
for args in "$@"
do
    case $args in
        -h|--help)
            printf "Help: \n"
            ;;
        -u|--user)
            echo "Setting user"
            admin_user=$2
            shift 2
            echo "User: $admin_user"
            ;;
        -p|--password)
            echo "Setting password"
            password_user=$2
            shift 2
            echo "Password set to ********"
            ;;
        -con|--connection)  
            echo "Add the connection string"
            conn=$2
            shift 2
            echo "Connection: $conn"
            ;;
        -c|--connect)
            echo "Establishing connection"
            echo "Starting MongoSH"
            echo "Connection Started"
            mongosh $conn --username $admin_user --password $password_user
            .exit
            ;;
        -b|--backup)
            printf "$green\n"
            echo "Backing up database"
            mongodump --uri "mongodb+srv://$admin_user:$password_user@mbw.jttju.mongodb.net" --out $backupFolder --forceTableScan
            echo "Database backed up at $backupFolder"
            printf "$resetRed"
            ;;
        -r|--restore)
            echo "Restoring database"
            mongorestore --uri "mongodb+srv://$admin_user:$password_user@mbw.jttju.mongodb.net" $backupFolder
            echo "Database restored"
            ;;
        -pk|--panic)
            echo "Anomaly detected entering panic"
            echo "Panic mode activated"
            mongo $conn --username $admin_user --password $password_user --eval "db.getSiblingDB('mbw').dropDatabase()"
            mongorestore --uri "mongodb+srv://$admin_user:$password_user@mbw.jttju.mongodb.net" $backupFolder
            echo "Panic mode deactivated"
            exit 0
            ;;
    esac
done

# case $1 in 
#     -h|--help)
#         echo "Usage: 
#         Commands: 
#         "
#         ;;
#     -u|--user)
#         admin_user=$2
#         echo $admin_user ;;
#     -p|--password)
#         password_user=$2
#         echo $password_user ;;
# esac