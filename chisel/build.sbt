name := "Patmos"

scalaVersion := "2.9.2"

resolvers ++= Seq(
  "scct-github-repository" at "http://mtkopone.github.com/scct/maven-repo"
)

scalacOptions ++= Seq("-unchecked", "-deprecation")

libraryDependencies <+= scalaVersion("org.scala-lang" % "scala-compiler" % _)

scalaSource in Compile <<= baseDirectory(_ / "src")

libraryDependencies += "edu.berkeley.cs" %% "chisel" % "1.0.8"