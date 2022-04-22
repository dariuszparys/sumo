#!/usr/bin/env python
# Eclipse SUMO, Simulation of Urban MObility; see https://eclipse.org/sumo
# Copyright (C) 2009-2022 German Aerospace Center (DLR) and others.
# This program and the accompanying materials are made available under the
# terms of the Eclipse Public License 2.0 which is available at
# https://www.eclipse.org/legal/epl-2.0/
# This Source Code may also be made available under the following Secondary
# Licenses when the conditions for such availability set forth in the Eclipse
# Public License 2.0 are satisfied: GNU General Public License, version 2
# or later which is available at
# https://www.gnu.org/licenses/old-licenses/gpl-2.0-standalone.html
# SPDX-License-Identifier: EPL-2.0 OR GPL-2.0-or-later

# @file    test.py
# @author  Pablo Alvarez Lopez
# @date    2019-07-16

# import common functions for netedit tests
import os
import sys

testRoot = os.path.join(os.environ.get('SUMO_HOME', '.'), 'tests')
neteditTestRoot = os.path.join(
    os.environ.get('TEXTTEST_HOME', testRoot), 'netedit')
sys.path.append(neteditTestRoot)
import neteditTestFunctions as netedit  # noqa

# Open netedit
neteditProcess, referencePosition = netedit.setupAndStart(neteditTestRoot, ['--gui-testing-debug-gl'])

# go to demand mode
netedit.supermodeDemand()

# go to vehicle mode
netedit.vehicleMode()

# select flow with embedded route
netedit.changeElement("flow (from-to junctions)")

# set invalid arrival pos
netedit.changeDefaultValue(netedit.attrs.flowJunction.create.terminate, "dummyTerminate")

# try to create flow with embedded route
netedit.leftClick(referencePosition, 80, 360)
netedit.leftClick(referencePosition, 85, 77)

# press enter to create flow with embedded route
netedit.typeEnter()

# set invalid arrival pos
netedit.changeDefaultValue(netedit.attrs.flowJunction.create.terminate, "end-number")

# create flow with embedded route
netedit.leftClick(referencePosition, 80, 360)
netedit.leftClick(referencePosition, 85, 77)

# press enter to create flow with embedded route
netedit.typeEnter()

# set valid arrival pos
netedit.changeDefaultValue(netedit.attrs.flowJunction.create.end, "dummy")

# create flow with embedded route
netedit.leftClick(referencePosition, 80, 360)
netedit.leftClick(referencePosition, 85, 77)

# press enter to create flow with embedded route
netedit.typeEnter()

# set valid arrival pos
netedit.changeDefaultValue(netedit.attrs.flowJunction.create.end, "-30")

# create flow with embedded route
netedit.leftClick(referencePosition, 80, 360)
netedit.leftClick(referencePosition, 85, 77)

# press enter to create flow with embedded route
netedit.typeEnter()

# set valid arrival pos
netedit.changeDefaultValue(netedit.attrs.flowJunction.create.end, "20.5")

# create flow with embedded route
netedit.leftClick(referencePosition, 80, 360)
netedit.leftClick(referencePosition, 85, 77)

# press enter to create flow with embedded route
netedit.typeEnter()

# set valid arrival pos
netedit.changeDefaultValue(netedit.attrs.flowJunction.create.end, "22")

# set valid arrival pos
netedit.changeDefaultValue(netedit.attrs.flowJunction.create.number, "dummy")

# create flow with embedded route
netedit.leftClick(referencePosition, 80, 360)
netedit.leftClick(referencePosition, 85, 77)

# press enter to create flow with embedded route
netedit.typeEnter()

# set valid arrival pos
netedit.changeDefaultValue(netedit.attrs.flowJunction.create.number, "-30")

# create flow with embedded route
netedit.leftClick(referencePosition, 80, 360)
netedit.leftClick(referencePosition, 85, 77)

# press enter to create flow with embedded route
netedit.typeEnter()

# set valid arrival pos
netedit.changeDefaultValue(netedit.attrs.flowJunction.create.number, "20.5")

# create flow with embedded route
netedit.leftClick(referencePosition, 80, 360)
netedit.leftClick(referencePosition, 85, 77)

# press enter to create flow with embedded route
netedit.typeEnter()

# set valid arrival pos
netedit.changeDefaultValue(netedit.attrs.flowJunction.create.number, "51")

# create flow with embedded route
netedit.leftClick(referencePosition, 80, 360)
netedit.leftClick(referencePosition, 85, 77)

# press enter to create flow with embedded route
netedit.typeEnter()

# Check undo redo
netedit.undo(referencePosition, 5)
netedit.redo(referencePosition, 5)

# save routes
netedit.saveRoutes(referencePosition)

# save network
netedit.saveNetwork(referencePosition)

# quit netedit
netedit.quit(neteditProcess)