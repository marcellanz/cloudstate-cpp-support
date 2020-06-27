#------------------
#lambda.sh 
#(c) H.Buchmann 2020
# calling lambda.sh java-source im src
#------------------
#we are in work
RELEASE=11
LIB=${PWD}/../java/lib
CP=${LIB}/aws-lambda-java-core-1.2.1.jar:${LIB}/aws-lambda-java-events-3.1.0.jar
SRC=$(realpath -e --relative-to=../src ${1})
STEM=${SRC%.java}
javac -d . --release=${RELEASE} -cp ${CP} ${1}

[[  ${?} -gt 0 ]] && exit 1

jar -c -f $(basename ${STEM}).jar ${STEM}*.class 
#${PWD}/../lib/aws-lambda-java-events-3.1.0.jar \
#${PWD}/../lib/joda-time-2.10.6.jar

#TODO use aws-cli
