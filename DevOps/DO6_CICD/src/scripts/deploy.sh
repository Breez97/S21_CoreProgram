#!/bin/bash

remote_user="root"
remote_host="192.168.1.72"
remote_dir=/usr/local/bin

artifacts=("../cat/s21_cat" "../grep/s21_grep")

for artifact in "${artifacts[@]}"; do
  if [ ! -e "$artifact" ]; then
    echo "Error: $artifact doesn't exist"
    exit 1
  fi
done

for artifact in "${artifacts[@]}"; do
  echo "Copying $artifact to $remote_user@$remote_host into $remote_dir"
  if scp "$artifact" ${remote_user}@${remote_host}:${remote_dir}; then
    echo -e "\033[32mSuccessfully copied\033[0m $artifact"
  else
    echo -e "\033[31mERROR: failed to copy\033[0m $artifact"
    exit 1
  fi
done

echo "Deployment completed successfully"
