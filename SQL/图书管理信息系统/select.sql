use ͼ�������Ϣϵͳ;

select ��������,�����Ա�,������λ,�绰���� from reader where �������� = (select ������ from reader_cate where �������� = '��ʿ��')

select �鼮���,�鼮����,��������,��������,(select ������� from book_cate where �����=book.�鼮���)as �鼮������� from book where ���������� = '��е��ҵ������'

select ���߱��,��������,������λ,�绰����,�ʼ���ַ,��������,�������� from reader,borrow_relatio
