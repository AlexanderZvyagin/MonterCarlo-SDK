from .binding import *

def BadModel ():
    m = Model()
    m.TimeStart = 0
    m.TimeSteps = 10
    m.NumPaths = 10000
    m.updaters.append(Updater(
        type = "Error",
        name = "Error"
    ))
    return m

def BuildModel_Simple ():
    m = Model()
    m.TimeStart = 0
    m.TimeSteps = 10
    m.NumPaths = 10000
    m.updaters.append(Updater(
        type = "IndependentBrownianMotion",
        name = "IndependentBrownianMotion"
    ))
    m.updaters.append(Updater(
        type = "SimpleBrownianMotion",
        name = "SimpleBrownianMotion",
        start = Parameter("start",0.1),
        args = [
            Parameter("drift",0.2),
            Parameter("diffusion",2)
        ]
    ))
    return m

def TwoProcessesModel ():
    m = Model()
    m.TimeStart = 0
    m.TimeSteps = 10
    m.NumPaths = 10000
    m.updaters.append(Updater(
        type = "IndependentBrownianMotion",
        name = "IndependentBrownianMotion"
    ))
    m.updaters.append(Updater(
        type = "SimpleBrownianMotion",
        name = "SimpleBrownianMotion",
        start = Parameter("start",0.1),
        args = [
            Parameter("drift",0.2),
            Parameter("diffusion",2)
        ]
    ))
    m.updaters.append(Updater(
        type = "SimpleBrownianMotion",
        name = "SimpleBrownianMotion",
        start = Parameter("start",0.1),
        args = [
            Parameter("drift",0.2),
            Parameter("diffusion",2)
        ]
    ))
    return m

def FxOption_vanilla ():
    m = Model()
    m.TimeStart = 0
    m.TimeSteps = 10
    m.NumPaths = 10000
    m.updaters.append(Updater(
        type = "IndependentBrownianMotion",
        name = "IndependentBrownianMotion"
    ))
    m.updaters.append(Updater(
        type = "SimpleGeometricalBrownianMotion",
        name = "SimpleGeometricalBrownianMotion",
        start = Parameter("start",130),
        args = [
            Parameter("drift",0.0),
            Parameter("diffusion",0.3)
        ]
    ))
    fxProcessNumber = m.NumStatefulProcesses()-1
    assert fxProcessNumber==0

    m.updaters.append(Updater(
        type = "Product_Option",
        name = "Product_Option",
        start = Parameter("call",None),
        args = [
            Parameter("myStrike",140),
            Parameter("myType",0) # call:0 put:1
        ],
        refs = [fxProcessNumber]
    ))
    callOptionOnFxProcessNumber = m.NumStatefulProcesses()-1

    assert callOptionOnFxProcessNumber == (fxProcessNumber+1)

    return m