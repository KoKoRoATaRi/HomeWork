use LMS;
insert book_cate values('1','��ѧ','���� ��ѧ','��');
insert book_cate values('2','����','���� ����','��');
insert book_cate values('3','�������ѧ����','���� �����','��');

insert reader_cate values('1','��ʦ',30,30,'��ʦÿ�����ɽ���30��������30��');
insert reader_cate values('2','������',10,10,'ѧ��ÿ�����ɽ���10��������10��');
insert reader_cate values('3','��ʿ��',10,10,'ѧ��ÿ�����ɽ���10��������10��');
insert reader_cate(num,name) values('4','������Ա');

insert reader(num,name,cate,sex,company) values('1','¬��',2,'��','���������Ƽ���ѧ');
insert reader(num,name,cate,sex,company) values('2','����ǿ��ʦ',1,'��','�������ӿƼ���ѧ');

insert book(num,name,cate,author_name,pub_name) values('1','���и���100��',1,'����ǿ','���������Ƽ���ѧ������');
insert book(num,name,cate,author_name,pub_name) values('2','���м����100��',3,'¬��','���������Ƽ���ѧ������');
insert book(num,name,cate,author_name,pub_name) values('3','���м��������',3,'¬��','���������Ƽ���ѧ������');
insert book(num,name,cate,author_name,pub_name) values('4','���������ѧ',3,'��ɺ','���������Ƽ���ѧ������');

insert borrow_relation(num,reader_num,book_num,out_time) values ('1','1','1','2017-11-27');

