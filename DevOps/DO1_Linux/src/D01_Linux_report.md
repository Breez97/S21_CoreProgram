## Part 1. Установка ОС

- Узнать версию Ubuntu, выполнив команду `cat /etc/issue`.
- Скриншот с выводом команды: \
	![Ubuntu Version](./images/part_1/ubuntu_version.png)

## Part 2. Создание пользователя

- Скриншот вызова команды для создания пользователя. Пользователь должен быть добавлен в группу `adm`. \
	Команда для создания и добавления пользователя в группу `adm` : `sudo useradd -G <group_name> <username>`. \
	![Add User](./images/part_2/add_user.png)
- Проверить, что пользователь успешно добавлен. Скриншот с результатом вывода. \
	Команда: `cat /etc/passwd`. \
	![Show /etc/passwd](./images/part_2/show_etc_passwd.png)

## Part 3. Настройка сети ОС

- Задать имя машины вида `user-1`. \
	Команда для изменения имени машины: `sudo hostnamectl set-hostname <name>`. \
	![Set Hostname](./images/part_3/set_hostname.png)
- Установить временную зону, соответствующую текущему местоположению. \
	Команда для установки врменной зоны: `sudo timedatectl set-timezone <name-timezone>`. \
	![Set Timezone](./images/part_3/set_local_time.png)
- Вывести названия сетевых интерфейсов с помощью консольной команды. \
	Для вывода сетевых интерфейсов воспользуемся следующей командой, она просто выводит список всех интерфейсов: `ls /sys/class/net`. \
	![Show Int](./images/part_3/show_int.png) \
	Для более подробной информации воспользуемся утилитой `ifconfig`. Для этого необходимо установить `net-tools`: `sudo apt install net-tools`. \
	![Show Int Ifconfig](./images/part_3/show_int_ifconfig.png)
	> **lo interface** (loopback) - виртуальный сетевой интерфейс на компьюетере, который "указывает" на сам компьютер. Он может использоваться для проверки, тестирования, настройки сетевых приложений и сервисов без реального подключения к другим компьютерам или сетям. С этим интерфейсом связан адрес 127.0.0.1 (`localhost`).
- Получить `ip-адрес` устройства, на котором происходит работа, от `DHCP` сервера, с помощью консольной команды. \
	Команда для отображения `ip-адреса`: `hostname -I` (`-I` - отображение всех сетевых адресов). \ 
	![Show Ip Hostname](./images/part_3/show_ip_hostname.png)
	> **DHCP (Dynamic Host Configuration Protocol)** - протокол прикладного уровня модели TCP/IP, благодаря которому клиенты в автоматическом режиме получают ip-адреса и другие настройки для подключения и обмена информацией.
- Вывести на экран внешний `ip-адрес` шлюза и внутренний `ip-адрес` адрес шлюза (он же `ip-адрес` по умолчанию - `gw`). \
	Команда для получения внешнего `ip-адреса`: `curl ifconfig.me/ip`. \
	![External IP](./images/part_3/external_ip.png) \
	Команда для получения внутреннего `ip-адреса`: `ip route`. \
	![Internal IP](./images/part_3/internal_ip.png)
- Задать статичные настройки `ip`, `gw`, `dns` (использовать публичные `DNS серверы`, например, `1.1.1.1` или `8.8.8.8`). \
	Для задания статичных `ip-адресов` откроем конфигурационный файл на редактирование: `sudo vim 00-installer-config.yaml`, который находится в папке `/etc/netplan`. \
	Файл до внесения изменений: \
	![Before Configuration](./images/part_3/before_configuration.png) \
	Файл после внесения изменений: \
	![After Configuration](./images/part_3/after_configuration.png) \
	После того, как все изменения были внесены, применим их и перезапустим систему: `sudo netplan apply`. \
	![Netplan Apply](./images/part_3/netplan_apply.png) \
	Убедимся в том, что изменения успешно применились. \
	![Check settings](./images/part_3/check_settings.png) \
	Пропингуем `1.1.1.1` и `ya.ru`. \
	![Test Ping](./images/part_3/test_ping.png)

## Part 4. Обновление ОС

- Обновить системные пакеты до последней версии. \
	Для обновления системных пакетов выполним команду: `sudo apt-get upgrade`. \
	![Packages Upgrade](./images/part_4/packages_upgrade.png)

## Part 5. Использование команды sudo

> **Sudo** - команда, которая временно наделяет правами суперпользователя. Её использует для задач администрирования и настройки системы с максимально доступными правами.

- Разрешить пользователю, созданному в [**Part 2**](#part-2-создание-пользователя) (raisinwr_copy), выполнять команду `sudo`. \
	Разрешим пользователю `raisinwr_copy` выполнение команды `sudo`: `sudo usermod -aG sudo raisinwr_copy`. \
	После этого проверим, что он действительно имеет доступ к команде `sudo`. Для этого изменим `hostname` от его имени: `sudo -u raisinwr_copy hostnamectl set-hostname raisinwr_copy-1`. \
	![Use sudo command](./images/part_5/set_sudo.png)

## Part 6. Установка и настройка службы времени

- Настроить службу автоматической синхронизации времени.
- Вывести время часового пояся, в котором сейчас находимся.
- Скриншот с результатом вывода команды `timedatectl show` (вывод должен содержать `NTPSynchronized=yes`). \
	![Timedate Show](./images/part_6/timedate_show.png)

## Part 7. Установка и использование текстовых редакторов

### Задание 1

- Установить текстовые редакторы `VIM` (+ любые два по желанию `NANO`, `MCEDIT`, `JOE` и т.д.). \
	Для установки воспользуемся командой: `sudo apt install vim nano mcedit`. \
	![Instll Editors](./images/part_7/installing_editors.png)

### Задание 2

- Используя каждый из трех выбранных редакторов, создать файл `test_X.txt`, где `X` - название редактора, в котором создан файл. Написать в нём свой никнейм, закрыть файл с сохранением изменений. \
	<br>**VIM**: `vim test_vim.txt`.<br>Для выхода: `ESC` -> `:wq` (`w - write`, `q - quit`). \
	![VIM Create](./images/part_7/vim_create.png) \
	<br>**NANO**: `nano test_nano.txt`.<br>Для выхода: `^X` (`ctrl`+`x`). \
	![NANO Create](./images/part_7/nano_create.png) \
	<br>**MCEDIT**: `mcedit test_mcedit.txt`.<br>Для сохранения: `F2`, для выхода: `F10`. \
	![MCEDIT Create](./images/part_7/mcedit_create.png)

### Задание 3

- Используя каждый из трех выбранных редакторов, открыть файл на редактирование, отредактировать файл, заменив никнейм на строку «21 School 21», закрыть файл без сохранения изменений. \
	<br>**VIM**<br>Для выхода без изменений: `:q!` (`force quit`). \
	![VIM Edit](./images/part_7/vim_edit.png) \
	<br>**NANO**<br>Для выхода без изменений: `^X` (`ctrl`+`x`) -> `N` (`No`). \
	![NANO Edit](./images/part_7/nano_edit.png) \
	<br> **MCEDIT**<br>Для выхода без изменений: `F10` -> `No`. \
	![MCEDIT Edit](./images/part_7/mcedit_edit.png)

### Задание 4

- Используя каждый из трех выбранных редакторов, отредактировать файл ещё раз (по аналогии с предыдущим пунктом), а затем освоить функции поиска по содержимому файла (слово) и замены слова на любое другое. \
	<br>**VIM**<br>**Поиск**<br>Для поиска открываем файл на редактирование и через `/<word>` выполняем поиск. \
	![VIM Search](./images/part_7/vim_search.png)
	<br>**Замена**<br>Для замены выполняем команду: `%s/<search_phrase>/<replace_phrase>/g`.<br>`%` - замена будет выполняться во всем файле от первой строки до последней.<br>`g` - замена всех вхождений в текущей строке. \
	![VIM Replace](./images/part_7/vim_replace.png)

	<br>**NANO**<br>**Поиск**<br>Для поиска открываем файл на редактирование и нажимаем `^W` (`ctrl`+`w`), после этого вводим то, что хотим найти. \
	![NANO Search](./images/part_7/nano_search.png)
	<br>**Замена**<br>Для замены необходимо нажать `^\` (`ctrl`+`\`). \
	![NANO Replace 1](./images/part_7/nano_replace_1.png)
	<br>После этого вводим то, что хотим заменить. \
	![NANO Replace 2](./images/part_7/nano_replace_2.png)
	<br>Вводим то, на что хотим заменить. \
	![NANO Replace 3](./images/part_7/nano_replace_3.png)
	<br>Подтверждаем действие нажатием `Y` (`Yes`). \
	![NANO Replace 4](./images/part_7/nano_replace_4.png)
	<br>Получаем результат. \
	![NANO Replace 5](./images/part_7/nano_replace_5.png)

	<br>**MCEDIT**<br>**Поиск**<br>Для поиска открываем файл на редактирование и нажимаем `F7`, после этого вводим то, что хотим найти. \
	![MCEDIT Search](./images/part_7/mcedit_search.png)
	<br>**Замена**<br>Для замены необходимо нажать `F4`, ввести то, что хотим заменить и то, на что заменить. \
	![MCEDIT Replace 1](./images/part_7/mcedit_replace_1.png)
	<br>Нажать `Yes` -> `All` и получить результат. \
	![MCEDIT Replace 2](./images/part_7/mcedit_replace_2.png)

## Part 8. Установка и базовая настройка сервиса SSHD

- Установить службу `SSHd`.
	1. Обновить репозиторий: `sudo apt update`.
	2. Установить `SSH`: `sudo apt-get install ssh`.
	3. Установить `OpenSSH`: `sudo apt install openssh-server`.
- Добавить автостарт при запуске системы: `sudo systemctl enable sshd`.
- Проверим работу `SSH`: `systemctl status sshd`. \
	![SSH Status](./images/part_8/ssh_status.png)
- Перенастроить службу `SSHd` на порт 2022. \
	Для этого откроем конфигурационный файл через текстовый редактор `vim`: `sudo vim /etc/ssh/sshd_config` и заменим, используемый там порт `22` на `2022`. После этого перезапустим систему \
	![SSH Change port](./images/part_8/change_port.png)
- Используя команду `ps` показать наличие процесса `sshd`. \
	Отобразим все процессы на `Linux` с помощью флага `-e` и через утилиту `grep` выберем процесс `sshd`: `ps -e | grep sshd`. \
	![SSH Process](./images/part_8/ssh_process.png)
- Перезапустим систему командой: `reboot`.
- Вывод команды `netstat -tan`. \
	![Netstat](./images/part_8/netstat.png)
	> Команда **netstat** отображает различную сетевую информацию, такую как сетевые подключения, статистику интерфейсов, таблицы маршрутизации и т.д. <br>**Значения ключей -tan**<br>**-t** - отображение соединения только по TCP.<br>**-a** - отображение состояния всех активных сокетов, которые ожидают или не ожидают подключения (программных интерфейсов для обеспечения обмена данными между процессами).<br>**-n** - отображает IP-адреса, вместо названия хостов.<br><br>**Значение столбцов**<br>**Proto** - протокол, используемый сокетом (tcp, udp, raw).<br>**Recv-Q** - количество байт, не скопированных программой пользователя из этого сокета.<br>**Send-Q** - количество байт, не подтвержденных удаленным хостом.<br>**Local Address** - адрес и номер порта локального конца сокета.<br>**Foreign Address** - адрес и номер порта удалённого конца сокета.<br>**State** - состояние сокета (в данном случае **LISTEN**, что означает, что сокет ожидает входящих подключений).<br><br>**0.0.0.0** - в таблице обозначает "любой адрес", соединении могут использовать все IP-адреса, существующие на данном компьютере.

## Part 9. Установка и использование улитилит **top**, **htop**

- Установить и запустить утилиты `top` и `htop`. \
	![Top Command Output](./images/part_9/top_output.png)
- По выводу команды определить:
	- **uptime** : `26 min`
	- **Количество авторизованных пользователей** : `1`
	- **Общую нагрузку системы** : `0.00, 0.00, 0.00` *(1-е значение - количество процессов, готовых к запуску за последнюю минуту, 2-е значение - за 5 минут, 3-е значение - за 15 минут)*.
	- **Общее количество процессов** : `100 total` *(1 running, 99 sleeping, 0 stopped, 0 zombie)*.
	- **Загрузку cpu** : `0.0 us, 0.0 sy, 0.0 ni, 99.8 id, 0.2 wa, 0.0 hi, 0.0 si, 0.0 st`
	- **Загрузку памяти** : `3920.0 (total), 3364.2 (free), 154.6 (used)`
	- **Pid процесса занимающего больше всего памяти** : `1048` (`shift`+`m` - отсортировать по используемой памяти). \
	![Memory Usage](./images/part_9/top_most_memory.png)
	- **Pid процесса, занимающего больше всего процессорного времени** : `1` \
	![Time Usage](./images/part_9/top_most_time.png)
- Вставить скриншот с выводом команды `htop`. \
	![HTop Comand Output](./images/part_9/htop_output.png)
	- **Отсортированный по `PID`.** <br>`htop --sort-key PID` \
	![HTop Sorted PID](./images/part_9/htop_sort_by_pid.png)
	- **Отсортированный по `PERCENT_CPU`.** <br>`htop --sort-key PERCENT_CPU` \
	![HTop Sorted PERCENT_CPU](./images/part_9/htop_sort_by_percent_cpu.png)
	- **Отсортированный по `PERCENT_MEM`.** <br>`htop --sort-key PERCENT_MEM` \
	![HTop Sorted PERCENT_MEM](./images/part_9/htop_sort_by_percent_mem.png)
	- **Отсортированный по `TIME`.** <br>`htop --sort-key TIME` \
	![HTop Sorted TIME](./images/part_9/htop_sort_by_time.png)
	- **Отфильтрованному для процесса `sshd`.** \
	![HTop Sorted sshd](./images/part_9/sort_sshd.png)
	- **С процессом `syslog`, найденным, используя поиск.** \
	![HTop Search Syslog](./images/part_9/search_syslog.png)
	- **С добавленным выводом `hostname`, `clock` и `uptime`.** \
	![HTop Add](./images/part_9/htop_add.png)
	![HTop Result](./images/part_9/htop_result.png)

## Part 10. Использование утилиты **fdisk**

- Запустить команду `fdisk -l`. \
	![Fdisk Output](./images/part_10/fdisk_output.png)
	- **Название жетского диска** : `VBOX HARDDISK`
	- **Размер жесткого диска** : `10 GiB`
	- **Количество секторов** : `20971520`
	- **Swap** : `файл подкачки отсутствует`

## Part 11. Использование утилиты **df**

- Запустить команду `df`. \
	![DF Output](./images/part_11/df_output.png)
	- **Размер корневого раздела** : `10215700`
	- **Размер занятого пространства корневого раздела** : `2889360`
	- **Размер свободного пространства корневого раздела** : `6785824`
	- **Процент использования корневого раздела** : `30%`
	- **Единица измерения** : по умолчанию используется `KiB`

- Запустить команду `df -Th`. \
	![DF Th Output](./images/part_11/df_Th_output.png)
	- **Размер корневого раздела** : `9.8G`
	- **Размер занятого пространства корневого раздела** : `2.8G`
	- **Размер свободного пространства корневого раздела** : `6.5G`
	- **Процент использования корневого раздела** : `30%`
	- **Тип файловой системы** : `ext4`

## Part 12. Использование утилиты **du**

- Запустить команду `du`. \
	![DU Output](./images/part_12/du_output.png)
- Вывести размер папок `/home`, `/var`, `/var/log` : `du -sh <folder_name>` (`-h` - human-readable, `-s` - summarize). \
	![DU Sumarize](./images/part_12/du_sumarize_size.png)
- Вывести размер всего содержимого в `/var/log`. \
	![Var Log](./images/part_12/var_log.png)

## Part 13. Установка и использование утилиты **ncdu**

- Установить утилиту `ncdu` : `sudo apt install ncdu`.
- Вывести размер папок `/home`, `/var`, `/var/log`. 
	- `sudo ncdu /home/` \
	![NCDU Home Size](./images/part_13/ncdu_home_size.png)	
	- `sudo ncdu /var/` \
	![NCDU Var Size](./images/part_13/ncdu_var_size.png)	
	- `sudo ncdu /var/log/` \
	![NCDU VarLog Size](./images/part_13/ncdu_varlog_size.png)

> `/home` : 128.0 KiB<br>`/var/` : 831.3 MiB<br>`/var/log/` : 127.4 MiB

## Part 14. Работа с системными журналами

- Открыть для просмотра.
	- `/var/log/dmesg` \
	![Dmesg](./images/part_14/dmesg.png)
	- `/var/log/syslog` \
	![Syslog](./images/part_14/syslog.png)
	- `/var/log/auth.log` \
	![Auth](./images/part_14/auth.png)
> **Время последней успешной авторизации** : `22:50:31`<br>**Bмя пользователя** : `raisinwr`<br>**Метод входа в систему** : `LOGIN`

- Перезапустить службу `SSHd` : `sudo systemctl restart sshd`. \
	![Restart SSHD](./images/part_14/restart_sshd.png)

## Part 15. Использование планировщика заданий **CRON**

- Используя планировщик заданий, запустить команду `uptime` через каждые 2 минуты.
	- Открыть файл планировщица задач: `crontab -e` и выбрать текстовый редактор, например `vim`. Вписываем необходимую задачу (`*/2` - выполнение каждые 2 минуты). \
	![Open CRON](./images/part_15/open_cron.png)
	- Найти в системных журналах строчки (минимум две в заданном временном диапазоне) о выполнении: `grep -i uptime /var/log/syslog`. \
	![Uptime](./images/part_15/show_uptime.png)
- Удалить все задания из планировщика заданий: `crontab -r`. \
	![Delete CRON](./images/part_15/delete_cron.png)
