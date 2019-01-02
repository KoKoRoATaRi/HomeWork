[x1 fs]=wavread('c:\outputfile.wav');
x1 = x1(:,1);
%% ������  --start
l=length(x1);%��������
t=l/fs;%����ʱ��
fs =0.2* fs;                        %���µ�������Ƶ��
l2 = t*fs;
B=l/l2; 
for i=1:l2
x2(i,:)=x1(round(i*B),:);%���²���
end

%% �˲�   --start
t=0:1/fs:(length(x2)-1)/fs;
wp=0.1*pi;ws=0.12*pi;               %���ֽ�Ƶ��
Rp=1;Rs=15;
Fs=0.5*fs;Ts=1/Fs;
wp1=2/Ts*tan(wp/2);                 %��ģ��ָ��ת��������ָ��
ws1=2/Ts*tan(ws/2); 
[N,Wn]=buttord(wp1,ws1,Rp,Rs,'s');  %ѡ���˲�������С����
[Z,P,K]=buttap(N);                  %����butterworthģ���˲���
[Bap,Aap]=zp2tf(Z,P,K);
[b,a]=lp2lp(Bap,Aap,Wn);
[bz,az]=bilinear(b,a,Fs);           %��˫���Ա任��ʵ��ģ���˲����������˲�����ת��
[H,W]=freqz(bz,az);                 %����Ƶ����Ӧ����
figure(1)
plot(W*Fs/(2*pi),abs(H))
grid
xlabel('Ƶ�ʣ�Hz')
ylabel('Ƶ����Ӧ����')
title('Butterworth')
f1=filter(bz,az,x2);
figure(2)
subplot(2,1,1)
plot(t,x2)                          %�����˲�ǰ��ʱ��ͼ

sound(x2,fs);
wavwrite(x2,fs,'c:\Ƿ�����˲�ǰ.wav');
title('�˲�ǰ��ʱ����');
subplot(2,1,2)
plot(t,f1);                         %�����˲����ʱ��ͼ
title('�˲����ʱ����');
sound(f1,fs);                    %�����˲�����ź�
wavwrite(f1,fs,'c:\Ƿ�����˲���.wav');
F0=fft(f1,1024);
f=fs*(0:511)/1024;
figure(3)
y2=fft(x2,1024);
subplot(2,1,1);
plot(f,abs(y2(1:512)));             %�����˲�ǰ��Ƶ��ͼ
title('�˲�ǰ��Ƶ��')
xlabel('Hz');
ylabel('fuzhi');
subplot(2,1,2)
F1=plot(f,abs(F0(1:512)));          %�����˲����Ƶ��ͼ
title('�˲����Ƶ��')
xlabel('Hz');
ylabel('fuzhi');
