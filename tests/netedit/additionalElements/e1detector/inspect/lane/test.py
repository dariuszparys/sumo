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
# @date    2016-11-25

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

# go to additional mode
netedit.additionalMode()

# select E1
netedit.changeElement("e1Detector")

# create E1
netedit.leftClick(referencePosition, 250, 210)

# go to inspect mode
netedit.inspectMode()

# inspect first E1
netedit.leftClick(referencePosition, 250, 210)

# Change parameter lane with a non valid value (dummy lane)
netedit.modifyAttribute(netedit.attrs.Enums.E1.inspect.lane, "dummy lane", True)

# Change parameter lane with a valid value (different edge)
netedit.modifyAttribute(netedit.attrs.Enums.E1.inspect.lane, "gneE0_0", True)

# Change parameter lane with a valid value (original edge, same lane)
netedit.modifyAttribute(netedit.attrs.Enums.E1.inspect.lane, "gneE2_1", True)

# Change parameter lane with a valid value (original edge, different lane)
netedit.modifyAttribute(netedit.attrs.Enums.E1.inspect.lane, "gneE2_0", True)

# Check undos and redos
netedit.undo(referencePosition, 4)
netedit.redo(referencePosition, 4)

# save additionals
netedit.saveAdditionals(referencePosition)

# save network
netedit.saveNetwork(referencePosition)

# quit netedit
netedit.quit(neteditProcess)
