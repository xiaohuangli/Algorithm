## Linux 版本

```
cat /etc/redhat-release
CentOS Linux release 7.6.1810
```

## nginx 安装

```
安装nginx源
yum localinstall http://nginx.org/packages/centos/7/noarch/RPMS/nginx-release-centos-7-0.el7.ngx.noarch.rpm
yum install nginx
service start nginx
```
## mysql
```
yum install mariadb-server mariadb 
yum install mysql mysql-devel
 
systemctl start mariadb  #启动MariaDB
systemctl stop mariadb  #停止MariaDB
systemctl restart mariadb  #重启MariaDB
systemctl enable mariadb  #设置开机启动

修改密码
mysql -u root -p
user mysql;
update user set password=password("123456")where user='root';
flush privileges;
exit
```
## php7

#### php7
```
rpm -Uvh https://mirror.webtatic.com/yum/el7/epel-release.rpm
rpm -Uvh https://mirror.webtatic.com/yum/el7/webtatic-release.rpm
yum install -y php71w php71w-cli php71w-common php71w-devel php71w-embedded php71w-fpm php71w-gd php71w-mbstring php71w-mysqlnd php71w-opcache php71w-pdo php71w-xml php71w-ldap php71w-mcrypt
```
#### php-grpc 扩展
```
安装grpc
git clone https://github.com/grpc/grpc.git
cd grpc
git submodule update --init
yum install -y libtool libsysfs
make && make install

安装扩展
cd grpc/src/php/ext/grpc
phpize
./configure
make && make install
//php.ini 添加 extension="/usr/lib64/php/modules/grpc.so"
php -m | grep grpc
```
#### php-protobuf 扩展
```
安装protoc
git clone  https://github.com/google/protobuf.git
./autogen.sh
./configure
make && make install

安装扩展
wget https://github.com/allegro/php-protobuf/archive/master.zip
unzip master.zip
cd php-protobuf-master
phpize
./configure 
make && make install
//然后在php.ini里面加一下extension="/usr/lib64/php/modules/protobuf.so"
php -m | grep protobuf
```

## nodejs 安装
```
yum install nodejs
node -v
npm -v
```
## composer
```
curl -sS https://getcomposer.org/installer | php
mv composer.phar /usr/local/bin/composer
composer -v
更换国内镜像
composer config -g repo.packagist composer https://packagist.phpcomposer.com
```
## laravel
```
composer create-project laravel/laravel server
```
