/*
 * Actuators and Propellers for the Patmos drone project (just the ocp interface for now)
 *
 * Authors: Luca Pezzarossa (lpez@dtu.dk)
 *
 */

package io

import Chisel._

object Actuators extends DeviceObject {
  var extAddrWidth = 32
  var dataWidth = 32

  def init(params : Map[String, String]) = {
    extAddrWidth = getPosIntParam(params, "extAddrWidth")
    dataWidth = getPosIntParam(params, "dataWidth")
  }

  def create(params: Map[String, String]) : Actuators = {
    Module(new Actuators(extAddrWidth=extAddrWidth, dataWidth=dataWidth))
  }

  trait Pins {
    val actuatorsPins = new Bundle() {
      val MCmd = UInt(OUTPUT,3)
      val MAddr = UInt(OUTPUT,extAddrWidth)
      val MData = UInt(OUTPUT,dataWidth)
      val MByteEn = UInt(OUTPUT,4)
      val SResp = UInt(INPUT,2)
      val SData = UInt(INPUT,dataWidth)
    }
  }
}

class Actuators(extAddrWidth : Int = 32,
                     dataWidth : Int = 32) extends CoreDevice() {
  override val io = new CoreDeviceIO() with Actuators.Pins
  //Assigments of inputs and outputs
  io.actuatorsPins.MCmd := io.ocp.M.Cmd
  io.actuatorsPins.MAddr := io.ocp.M.Addr(extAddrWidth-1, 0)
  io.actuatorsPins.MData := io.ocp.M.Data
  io.actuatorsPins.MByteEn := io.ocp.M.ByteEn
  io.ocp.S.Resp := io.actuatorsPins.SResp
  io.ocp.S.Data := io.actuatorsPins.SData
}
