i = 10;    %��������
r = 10;     %��Χ
dt = 0.01;  %���
w = 1;      %��Ƶ��
%%%%%%%%%%%%%%%%%%
n = 1;
t = -r:dt:r;
bn = 4/(n*pi);
y = bn*sin(w*t);
plot(t,y);
a = input('�밴���������');
for ii = 1:i
    xlabel({'��',num2str(ii),'��'});
    hold on;
    n = n + 2;
    bn = 4/(n*pi);
    yn = bn*sin(n*w*t);
    comet(t,yn);
    y = y + yn;
    hold off;
    axis equal;
    plot(t,y);
    xlabel({'��',num2str(ii),'��'});
    pause(1);    
end