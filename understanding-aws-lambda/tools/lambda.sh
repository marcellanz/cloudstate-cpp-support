#------------------
#lambda.sh 
#(c) H.Buchmann 2020
# calling lambda.sh java-source im src
#------------------
#we are in work
RELEASE=8
CP=${PWD}/../lib/aws-lambda-java-core-1.2.1.jar
SRC=$(realpath -e --relative-to=../src ${1})
STEM=${SRC%.java}
javac -d . --release=${RELEASE} -cp ${CP} ${1}
jar -c -f $(basename ${STEM}).jar ${STEM}.class

#TODO use aws-cli
