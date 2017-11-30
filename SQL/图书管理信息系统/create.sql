use master
DROP DATABASE ͼ�������Ϣϵͳ 
go
create database ͼ�������Ϣϵͳ
on
(
name = 'ͼ�������Ϣϵͳ_dat',
filename = 'c:\ͼ�������Ϣϵͳ.mdf',
size = 10,
maxsize = 50,
filegrowth = 5
)
log on
(
name = 'ͼ�������Ϣϵͳ_log',
filename = 'c:\ͼ�������Ϣϵͳ.ldf',
size = 5,
maxsize = 25,
filegrowth = 5mb
)
go
use ͼ�������Ϣϵͳ

create table book_cate
(
����� char(50) primary key,
������� char(20),
�ؼ��� char(50),
��ע��Ϣ char(50)
)

create table book
(
�鼮��� char(50) primary key,
�鼮���� char(50), 
�鼮���  char(50) foreign key references book_cate(�����), 
�������� char(50) ,
���������� char(50),
�������� datetime,
�鼮ҳ�� int,
�ؼ��� char(50),
�Ǽ����� datetime,
��ע��Ϣ char(50),
)
create table reader_cate
(
������ char(50) primary key,
�������� char(20),
�������� int ,
�������� int,
��ע��Ϣ char(50)
)

create table reader
(
���߱�� char(50) primary key,
�������� char(10),
�������� char(50) foreign key references reader_cate(������),
�����Ա� char (4),
������λ char(50),
��ͥ��ַ char(50),
�绰���� char(11),
�����ʼ���ַ char(20),
��֤���� datetime ,
��ע��Ϣ char(50),
)

create table borrow_relation
(
���ı�� char(50) primary key,
���߱�� char(50) foreign key references reader(���߱��),
�鼮��� char(50) foreign key references book(�鼮���),
�������� datetime not null,
�������� datetime,
��ע��Ϣ char(50)
)

