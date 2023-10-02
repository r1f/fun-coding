data<-read.table(file="DK.txt", header=TRUE, sep="\t")

#-------ex1(Check if there are outliers in the data)-------#

boxplot(data$Weight, ylab="Weight", main="Boxplot of Weight")
boxplot.stats(data$Weight)$out

boxplot(data$Growth, ylab="Growth", main="Boxplot of Growth")
boxplot.stats(data$Growth)$out

boxplot(data$BMI, ylab="BMI", main="Boxplot of BMI")
boxplot.stats(data$BMI)$out

#-------ex2-------#

summary(data$Weight)
summary(data$Growth)
summary(data$BMI)

#-------ex3 (Check the data for consistency)-------#

#----a (Normal distribution)----#

hist(rnorm(na.omit(data$Weight)), main = "Normal Distribution of Weight")
hist(rnorm(na.omit(data$Growth)), main = "Normal Distribution of Growth")
hist(rnorm(na.omit(data$BMI)), main = "Normal Distribution of BMI")

#----b (Student's t-distribution)----#

hist(dt(data$Weight, df=2), main = "Student’s Distribution of Weight")
hist(dt(data$Growth, df=2), main = "Student’s Distribution of Growth")
hist(dt(data$BMI, df=2), main = "Student’s Distribution of BMI")

#----c (Chi-squared distribution)----#

chisq.test(na.omit(data$Weight))
chisq.test(na.omit(data$Growth))
chisq.test(na.omit(data$BMI))

#-------ex4-------#

install.packages("Rcmdr")
library("Rcmdr")

#----a----#

local({
  .x <- seq(-3.291, 3.291, length.out=1000)  
  plotDistr(.x, pnorm(.x, mean=0, sd=1), cdf=TRUE, xlab="x", 
            ylab="Cumulative Probability", 
            main=paste("Normal Distribution:  Mean=0, Standard deviation=1"))
})

#----b----#

local({
  .x <- seq(-636.619, 636.619, length.out=1000)  
  plotDistr(.x, dt(.x, df=1), cdf=FALSE, xlab="x", ylab="Density", 
            main=paste("t Distribution:  Degrees of freedom=1"))
})

#----c----#

local({
  .x <- seq(0, 12.116, length.out=1000)  
  plotDistr(.x, pchisq(.x, df=1), cdf=TRUE, xlab="x", 
            ylab="Cumulative Probability", 
            main=paste("ChiSquared Distribution:  Degrees of freedom=1"))
})

