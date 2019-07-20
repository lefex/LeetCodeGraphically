//
//  Download.swift
//  LEFDataStructure
//
//  Created by Wang,Suyan on 2019/7/13.
//  Copyright © 2019 WSY. All rights reserved.
//

import Foundation

class Download1 {
    enum State {
        case waiting
        case downloading
        case successed
        case falied
        case noPermission
    }
    
    func stateChanged(state: State) {
        if state == .waiting {
            waitingAction()
        } else if state == .downloading {
            downloadingAction()
        } else if state == .successed {
            successedAction()
        } else if state == .noPermission {
            noPermission()
        } else {
            faliedAction()
        }
    }
    
    func waitingAction() {
        print("Waiting")
    }
    
    func downloadingAction() {
        print("downloading")
    }
    
    func successedAction() {
        print("successed")
    }
    
    func faliedAction() {
        print("falied")
    }
    
    func noPermission() {
        print("noPermission")
    }
}

protocol StateAble {
    func stateAction();
}

class Waiting: StateAble {
    func stateAction() {
        print("Waiting")
    }
}

class Downloading: StateAble {
    func stateAction() {
        print("Downloading")
    }
}

class Successed: StateAble {
    func stateAction() {
        print("Successed")
    }
}

class Falied: StateAble {
    func stateAction() {
        print("Falied")
    }
}

class NoPermission: StateAble {
    func stateAction() {
        print("noPermission")
    }
}

class Dowload {
    var curState: StateAble?
    
    func stateChanged(state: StateAble) {
        state.stateAction()
    }
}

class Use {
func testDonwload()  {
    let dow = Dowload()
    dow.stateChanged(state: Waiting())
    dow.stateChanged(state: Downloading())
    dow.stateChanged(state: Successed())
    dow.stateChanged(state: NoPermission())
}
}
