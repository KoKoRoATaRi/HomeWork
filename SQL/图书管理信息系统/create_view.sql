use ͼ�������Ϣϵͳ;
drop view �������ѧ������ͼ,�����_��ɺ,����_������

GO
create view �������ѧ������ͼ (�鼮��ϢID,�鼮����,��������,������,��������) as select �鼮���,�鼮����,��������,����������,�������� from book where �鼮��� = (select ����� from book_cate where �������='�������ѧ����') WITH CHECK OPTION 
GO
create view �����_��ɺ (�鼮��ϢID,�鼮����,��������,������,��������) as select �鼮���,�鼮����,��������,����������,�������� from book where �鼮��� = (select ����� from book_cate where �������='�������ѧ����') and �������� = '��ɺ' WITH CHECK OPTION 
Go
create view ����_������ as select * from reader where ������λ = '���������Ƽ���ѧ' WITH CHECK OPTION 



