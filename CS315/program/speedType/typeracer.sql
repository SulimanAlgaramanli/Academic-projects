-- phpMyAdmin SQL Dump
-- version 5.2.0
-- https://www.phpmyadmin.net/
--
-- Host: 127.0.0.1
-- Generation Time: Jul 11, 2022 at 09:56 PM
-- Server version: 10.4.24-MariaDB
-- PHP Version: 8.1.6

SET SQL_MODE = "NO_AUTO_VALUE_ON_ZERO";
START TRANSACTION;
SET time_zone = "+00:00";


/*!40101 SET @OLD_CHARACTER_SET_CLIENT=@@CHARACTER_SET_CLIENT */;
/*!40101 SET @OLD_CHARACTER_SET_RESULTS=@@CHARACTER_SET_RESULTS */;
/*!40101 SET @OLD_COLLATION_CONNECTION=@@COLLATION_CONNECTION */;
/*!40101 SET NAMES utf8mb4 */;

--
-- Database: `typeracer`
--

-- --------------------------------------------------------

--
-- Table structure for table `game`
--

CREATE TABLE `game` (
  `textid` int(11) NOT NULL,
  `userid` int(11) NOT NULL,
  `speed` int(11) DEFAULT NULL,
  `mistake` int(11) DEFAULT NULL
) ENGINE=InnoDB DEFAULT CHARSET=utf8mb4;

-- --------------------------------------------------------

--
-- Table structure for table `playeruser`
--

CREATE TABLE `playeruser` (
  `userId` int(11) NOT NULL,
  `userName` varchar(20) DEFAULT NULL,
  `password` varchar(50) DEFAULT NULL,
  `email` varchar(80) DEFAULT NULL,
  `admin` int(11) DEFAULT NULL,
  `miskakes` int(11) DEFAULT NULL,
  `speedAvg` float DEFAULT NULL
) ENGINE=InnoDB DEFAULT CHARSET=utf8mb4;

--
-- Dumping data for table `playeruser`
--

INSERT INTO `playeruser` (`userId`, `userName`, `password`, `email`, `admin`, `miskakes`, `speedAvg`) VALUES
(1, 'sa', 'sa', 'sa@gmail.com', 1, 0, 0),
(2, 'sami', 'hhhh', 'sami@gmail.com', NULL, NULL, NULL),
(4, 'mohamed', 'e45t', 'mohamed@gmail.com', NULL, NULL, NULL),
(5, 'suliman', 'zxcv', 'sal@gmail.com', NULL, NULL, NULL),
(6, 'anas', 'dfgh', 'anas@gmail.com', NULL, NULL, NULL),
(7, 'waled', 'poiu', 'waled32@gmail.com', NULL, NULL, NULL),
(8, 'salem', 'yes2', 'salem55@gmail.com', NULL, NULL, NULL),
(9, 'mohammed', 'uytr', 'mohammed@gmail.com', NULL, NULL, NULL),
(10, 'taher', '2211', 'taher21@gmail.com', NULL, NULL, NULL),
(11, 'hatem', '3323', 'ha3424@gmail.com', NULL, NULL, NULL),
(12, 'zeyad', '1112', 'zy33@gmial.com', NULL, NULL, NULL);

-- --------------------------------------------------------

--
-- Table structure for table `printtext`
--

CREATE TABLE `printtext` (
  `id` int(11) NOT NULL,
  `message` varchar(1000) DEFAULT NULL,
  `language` varchar(10) DEFAULT NULL,
  `levelGame` int(11) DEFAULT NULL
) ENGINE=InnoDB DEFAULT CHARSET=utf8mb4;

--
-- Dumping data for table `printtext`
--

INSERT INTO `printtext` (`id`, `message`, `language`, `levelGame`) VALUES
(1, 'Welcome in CS315 course', 'EN', 1),
(2, 'Hi Suliman', 'EN', 1),
(3, 'I am so Happy , Iam good devoleper .', 'En', 2),
(4, 'asdfg', 'En', 1),
(5, 'qwertyuiop', 'EN', 1);

--
-- Indexes for dumped tables
--

--
-- Indexes for table `game`
--
ALTER TABLE `game`
  ADD KEY `textid` (`textid`),
  ADD KEY `userid` (`userid`);

--
-- Indexes for table `playeruser`
--
ALTER TABLE `playeruser`
  ADD PRIMARY KEY (`userId`);

--
-- Indexes for table `printtext`
--
ALTER TABLE `printtext`
  ADD PRIMARY KEY (`id`);

--
-- AUTO_INCREMENT for dumped tables
--

--
-- AUTO_INCREMENT for table `playeruser`
--
ALTER TABLE `playeruser`
  MODIFY `userId` int(11) NOT NULL AUTO_INCREMENT, AUTO_INCREMENT=13;

--
-- AUTO_INCREMENT for table `printtext`
--
ALTER TABLE `printtext`
  MODIFY `id` int(11) NOT NULL AUTO_INCREMENT, AUTO_INCREMENT=6;

--
-- Constraints for dumped tables
--

--
-- Constraints for table `game`
--
ALTER TABLE `game`
  ADD CONSTRAINT `game_ibfk_1` FOREIGN KEY (`textid`) REFERENCES `printtext` (`id`) ON DELETE CASCADE,
  ADD CONSTRAINT `game_ibfk_2` FOREIGN KEY (`userid`) REFERENCES `playeruser` (`userId`) ON DELETE CASCADE;
COMMIT;

/*!40101 SET CHARACTER_SET_CLIENT=@OLD_CHARACTER_SET_CLIENT */;
/*!40101 SET CHARACTER_SET_RESULTS=@OLD_CHARACTER_SET_RESULTS */;
/*!40101 SET COLLATION_CONNECTION=@OLD_COLLATION_CONNECTION */;
