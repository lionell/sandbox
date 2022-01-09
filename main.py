import docker
import timeit

client = docker.from_env()

print(timeit.timeit(lambda: client.containers.run("hello-world"), number=20))
