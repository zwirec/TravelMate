CREATE DATABASE IF NOT EXISTS travelmate;

START TRANSACTION;

CREATE USER IF NOT EXISTS tm_connect@'localhost'
  IDENTIFIED BY '$5E0sA%ra5t*0R92';
GRANT ALL ON travelmate.* TO `tm_connect@'localhost'`
IDENTIFIED BY '$5E0sA%ra5t*0R92';

CREATE USER IF NOT EXISTS tm_connect@'%'
  IDENTIFIED BY '$5E0sA%ra5t*0R92';
GRANT ALL ON travelmate.* TO `tm_connect@'%'`
IDENTIFIED BY '$5E0sA%ra5t*0R92';

COMMIT;

USE travelmate;

START TRANSACTION;

CREATE TABLE IF NOT EXISTS country (
  name          CHAR(30) PRIMARY KEY,
  capital_id    SMALLINT UNSIGNED,
  visa_required BOOL NOT NULL
);

CREATE TABLE IF NOT EXISTS city (
  id           INTEGER UNSIGNED PRIMARY KEY AUTO_INCREMENT,
  name         CHAR(30) NOT NULL,
  country_name CHAR(30) NOT NULL
);

CREATE TABLE IF NOT EXISTS native_language (
  id           INTEGER UNSIGNED PRIMARY KEY AUTO_INCREMENT,
  country_name CHAR(30) NOT NULL,
  language     CHAR(3)  NOT NULL,
  percent      TINYINT UNSIGNED
);

CREATE TABLE IF NOT EXISTS user (
  id          INTEGER UNSIGNED PRIMARY KEY AUTO_INCREMENT,
  login       CHAR(30) UNIQUE NOT NULL,
  password    char(73) NOT NULL,
  user_avatar CHAR(30) NOT NULL            DEFAULT 'default_avatar'
);

CREATE TABLE IF NOT EXISTS contacts (
  user_id   INTEGER UNSIGNED PRIMARY KEY AUTO_INCREMENT,
  email     CHAR(30) NOT NULL,
  phone     CHAR(20) NULL,
  instagram CHAR(30) NULL,
  vk        CHAR(30) NULL
);

CREATE TABLE IF NOT EXISTS access (
  user_id    CHAR(30) PRIMARY KEY,
  last_login TIMESTAMP NOT NULL
);

CREATE TABLE IF NOT EXISTS journeys (
  id           INTEGER UNSIGNED PRIMARY KEY AUTO_INCREMENT,
  user_id      INTEGER UNSIGNED NOT NULL,
  from_city_id INTEGER UNSIGNED NOT NULL,
  to_city_id   INTEGER UNSIGNED NOT NULL,
  start_date   DATE             NOT NULL,
  end_date     DATE             NOT NULL
);


COMMIT;

