//
//  ViewController.swift
//  MLRecodeAudio
//
//  Created by Mrlu on 19/10/2017.
//  Copyright © 2017 Mrlu. All rights reserved.
//

import UIKit

class ViewController: UIViewController {
    
    @IBOutlet weak var startBtn: UIButton!
    @IBOutlet weak var stopBtn: UIButton!
    
    lazy var recorder:MLAudioBufferRecorder = {
//        let recorder:MLRecordAudio = MLRecordAudio()
        let recorder:MLAudioBufferRecorder = MLAudioBufferRecorder()
        return recorder
    }()
    
    override func viewDidLoad() {
        super.viewDidLoad()
        // Do any additional setup after loading the view, typically from a nib.
    }

    override func didReceiveMemoryWarning() {
        super.didReceiveMemoryWarning()
        // Dispose of any resources that can be recreated.
    }

    @IBAction func startAction(_ sender: Any) {
        if recorder.isKind(of: MLAudioBufferRecorder.self) {
            recorder.startRecord({ (start) in
                
            })
        } else {
            recorder.startRecord()
        }
    }
    
    @IBAction func stopAction(_ sender: Any) {
        recorder.stopRecord()
    }
}

