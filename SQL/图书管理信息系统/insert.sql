use ͼ�������Ϣϵͳ
insert book_cate values(1,'��ѧ','���� ��ѧ','��')
insert book_cate values(2,'����','���� ����','��')

insert reader_cate values(1,'��ʦ',30,30,'��ʦÿ�����ɽ���30��������30��')
insert reader_cate values(2,'ѧ��',10,10,'ѧ��ÿ�����ɽ���10��������10��')

insert reader_cate(������,��������) values(3,'������Ա')
insert reader(���߱��,��������,��������,�����Ա�,������λ) values(1,'¬��',2,'��','���������Ƽ���ѧ')
insert book(�鼮���,�鼮����,�鼮���,��������,����������) values(1,'���и���100��',1,'����ǿ','���������Ƽ���ѧ������')

insert borrow_relation(���ı��,���߱��,�鼮���,��������) values (1,1,1,'2017-11-27')


select * from borrow_relation