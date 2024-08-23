#!/bin/bash

source /home/gitlab-runner/tg_bot_config.conf

if [ "$CI_JOB_STATUS" == "success" ]; then
  MESSAGE="✅ Success%0A%0AProject name: $CI_PROJECT_NAME%0A%0ABranch: $CI_COMMIT_REF_NAME%0ACommit message: $CI_COMMIT_MESSAGE%0AStage: $CI_JOB_STAGE%0AJob $CI_JOB_NAME has been successfully completed%0A%0A$CI_PROJECT_URL/pipelines"
else
  MESSAGE="❌ Failure%0A%0AProject name: $CI_PROJECT_NAME%0A%0ABranch: $CI_COMMIT_REF_NAME%0ACommit message: $CI_COMMIT_MESSAGE%0AStage: $CI_JOB_STAGE%0AJob $CI_JOB_NAME ended with an error%0A%0A$CI_PROJECT_URL/pipelines"
fi

curl -X POST "https://api.telegram.org/bot${BOT_TOKEN}/sendMessage" -d "chat_id=${CHAT_ID}" -d "text=${MESSAGE}"
