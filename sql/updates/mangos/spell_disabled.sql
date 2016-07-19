/*
Navicat MySQL Data Transfer

Source Server         : localhost_3306
Source Server Version : 50540
Source Host           : localhost:3306
Source Database       : test60_w

Target Server Type    : MYSQL
Target Server Version : 50540
File Encoding         : 65001

Date: 2016-07-19 13:47:04
*/

SET FOREIGN_KEY_CHECKS=0;

-- ----------------------------
-- Table structure for `spell_disabled`
-- ----------------------------
DROP TABLE IF EXISTS `spell_disabled`;
CREATE TABLE `spell_disabled` (
  `entry` int(5) NOT NULL AUTO_INCREMENT,
  `disable_mask` int(5) DEFAULT NULL,
  PRIMARY KEY (`entry`)
) ENGINE=MyISAM AUTO_INCREMENT=10915 DEFAULT CHARSET=gbk;

-- ----------------------------
-- Records of spell_disabled
-- ----------------------------
INSERT INTO `spell_disabled` VALUES ('605', '1');
INSERT INTO `spell_disabled` VALUES ('10911', '1');
INSERT INTO `spell_disabled` VALUES ('10912', '1');
