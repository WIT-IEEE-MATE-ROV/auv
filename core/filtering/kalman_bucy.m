clear;set(0,’defaultaxesfontsize’,20);format long
%%% p8c.m Kalman-Bucy Filter
%% setup

J=1e4;% number of steps
N=2;%dimension of state
I=eye(N);% identity operator
gamma=1;% observational noise variance is gammaˆ2*I
sigma=1;% dynamics noise variance is sigmaˆ2*I
C0=eye(2);% prior initial condition variance
m0=[0;0];% prior initial condition mean
sd=10;rng(sd);% choose random number seed
A=[-1 1;-1 -1];% dynamics determined by A
tau=0.01;% time discretization is tau
L=expm(A*tau);% forward semigroup operator
Sigma=sigmaˆ2*((A+A’)\(L*L’-I));% dynamics noise variance integrated
sqrtS=sqrtm(Sigma);

m=zeros(N,J+1);v=m;z=zeros(J+1,1);c=zeros(N,N,J+1);% pre-allocate
v(:,1)=m0+sqrtm(C0)*randn(N,1);% initial truth
m(:,1)=10*randn(N,1);% initial mean/estimate
c(:,:,1)=100*C0;% initial covariance
z(1)=0;% initial ghost observation
H=[1,0];% observation operator

%% solution % assimilate!

for j=1:J
    v(:,j+1)=L*v(:,j) + sqrtS*randn(N,1);% truth
    z(j+1)=z(j)+tau*H*v(:,j+1) + gamma*sqrt(tau)*randn;% observation
    
    mhat=L*m(:,j);% estimator intermediate "predict"
    chat=L*c(:,:,j)*L’+Sigma;% covariance intermediate "predict"
    
    d=(z(j+1)-z(j))/tau-H*mhat;% "innovation"
    K=(tau*chat*H’)/(H*chat*H’*tau+gammaˆ2);% "Kalman gain"
    m(:,j+1)=mhat+K*d;% estimator "update"
    c(:,:,j+1)=(I-K*H)*chat;% covariance "update"
end

figure;js=501;plot(tau*[0:js-1],v(2,1:js));hold;plot(tau*[0:js-1],
m(2,1:js)...
,’m’); plot(tau*[0:js-1],m(2,1:js)+reshape(sqrt(c(2,2,1:js)),1,js),’r--’);
plot(tau*[0:js-1],m(2,1:js)-reshape(sqrt(c(2,2,1:js)),1,js),’r--’);
hold;grid;xlabel(’t’);
title(’Kalman-Bucy Filter’);
figure;plot(tau*[0:J],reshape(c(1,1,:)+c(2,2,:),J+1,1));hold
plot(tau*[0:J],cumsum(reshape(c(1,1,:)+c(2,2,:),J+1,1))./[1:J+1]’,...
’m’,’Linewidth’,2); grid;hold;xlabel(’t’);axis([0 tau*J 0 50]);
title(’Kalman-Bucy Filter Covariance’);
figure;plot(tau*[0:J],sum((v-m).ˆ2));hold;
plot(tau*[0:J],cumsum(sum((v-m).ˆ2))./[1:J+1],’m’,’Linewidth’,2);grid
hold;xlabel(’t’);axis([0 tau*J 0 50]);
title(’Kalman-Bucy Filter Error’)