chamilo

CHAMILO INSTALACIÓN

https://11.chamilo.org/documentation/installation_guide.html#1._Pre-requisites
apt install mariadb-server apache2 php7.3
a2enmod rewrite
systemctl restart apache2
service apache2 status
apache2 -V

vi /etc/apache2/apache2.conf

    <Directory />
        AllowOverride All
        Require all granted
    </Directory>
    <Directory /var/www/chamilo/>
        AllowOverride All
        Require all granted
    </Directory>

# apache2
/etc/apache2/sites-enabled
vi 000-default.conf
ServerAdmin webmaster@localhost
DocumentRoot /var/www/chamilo

service apache2 restart

INSTALACIÓN
cd /var/www/
wget https://github.com/chamilo/chamilo-lms/releases/download/v1.11.16/chamilo-1.11.16.tar.gz
tar xvf chamilo-1.11.16.tar.gz
mv chamilo-1.11.16 chamilo

# Complementos PHP
apt install php-zip php-xml php-json php-gd php-curl php-apcu php-mysql php-intl

service apache2 restart

PHP CONFIG
post_max_size = 100M
upload_max_filesize = 100M
session.cookie_httponly = true


# Base de datos

mysql -u root
CREATE DATABASE chamilo;
CREATE USER johnny@localhost IDENTIFIED BY 'samus.com';
SELECT User FROM mysql.user;
GRANT ALL PRIVILEGES ON *.* TO johnny@localhost IDENTIFIED BY 'samus.com';
FLUSH PRIVILEGES;
SHOW GRANTS FOR johnny@localhost;

POST INSTALACION

cd /var/www/chamilo/app/config
chmod -R 0555 *
cd  /var/www/chamilo/
rm -r main/install/
