
  Assignment to ch:
  [-]
   Read into ch
   ,
   copy ch to m3
   [->>>>+<<<<]>>>>[-<<<<+>>>+>]
  while m3
  <[[-]
       Add 48 to m6
       >>>>++++++[-<++++++++>]<
       copy ch to m7
       <<<<<<[->>>>>>>>+<<<<<<<<]>>>>>>>>[-<<<<<<<<+>>>>>>>+>]
      m6 less than or equal m7 to m5
      <[->>+<<<[->>+<<]>>[-[-<<+>>]>-<]<]>>[-<<+>>]<<[-]<<+>[[-]<->]
       copy ch to m7
       <<<<<<[->>>>>>>>+<<<<<<<<]>>>>>>>>[-<<<<<<<<+>>>>>>>+>]
       Add 57 to m8
       >+++++++[-<++++++++>]<+
      m7 less than or equal m8 to m6
      [->>+<<<[->>+<<]>>[-[-<<+>>]>-<]<]>>[-<<+>>]<<[-]<<+>[[-]<->]
     and m5 and m6 to m4
     <<[[-]>[-<<+>>]<]>[-]
    if m4 (m3)
    <<<+>[[-]<-
       copy mode to m5
       <[->>>>+<<<<]>>>>[-<<<<+>>>+>]
      if m5 (m4)
      <<+>[[-]<-
           copy ch to m5
           <<<<[->>>>>>>+<<<<<<<]>>>>>>>[-<<<<<<<+>>>>>+>>]
           Add 48 to m6
           ++++++[-<++++++++>]<
          subtract m6 from m5
          [-<->]
          copy output to m5
          <<<<<[->>>>>+<<<<<]>>>>>[-<<<<<+>>>>+>]
        Write m5
        <.[-]
        dec mode
        <<<-
      else (m4)
      >>>]<[[-]
        Assignment to output:
        <<<[-]
           copy ch to m5
           <[->>>>>>>+<<<<<<<]>>>>>>>[-<<<<<<<+>>>>>+>>]
           Add 48 to m6
           ++++++[-<++++++++>]<
          subtract m6 from m5
          [-<->]
          Add 16 to m6
          >++++[-<++++>]<
         add m5 times m6 to output
         <[->[->+<]>[-<+<<<<<+>>>>>>]<<]>[-]
        inc mode
        <<<<+>>]
    else (m3)
    ]<[[-]
         Add 65 to m7
         >>>>>++++++++[-<++++++++>]<+
         copy ch to m8
         <<<<<<<[->>>>>>>>>+<<<<<<<<<]>>>>>>>>>[-<<<<<<<<<+>>>>>>>>+>]
        m7 less than or equal m8 to m6
        <[->>+<<<[->>+<<]>>[-[-<<+>>]>-<]<]>>[-<<+>>]<<[-]<<+>[[-]<->]
         copy ch to m8
         <<<<<<<[->>>>>>>>>+<<<<<<<<<]>>>>>>>>>[-<<<<<<<<<+>>>>>>>>+>]
         Add 70 to m9
         >+++++++[-<++++++++++>]<
        m8 less than or equal m9 to m7
        [->>+<<<[->>+<<]>>[-[-<<+>>]>-<]<]>>[-<<+>>]<<[-]<<+>[[-]<->]
       and m6 and m7 to m5
       <<[[-]>[-<<+>>]<]>[-]
      if m5 (m4)
      <<<+>[[-]<-
         copy mode to m6
         <<[->>>>>+<<<<<]>>>>>[-<<<<<+>>>>+>]
        if m6 (m5)
        <<+>[[-]<-
             copy ch to m6
             <<<<<[->>>>>>>>+<<<<<<<<]>>>>>>>>[-<<<<<<<<+>>>>>>+>>]
             Add 55 to m7
             +++++[-<+++++++++++>]<
            subtract m7 from m6
            [-<->]
            copy output to m6
            <<<<<<[->>>>>>+<<<<<<]>>>>>>[-<<<<<<+>>>>>+>]
          Write m6
          <.[-]
          dec mode
          <<<<-
        else (m5)
        >>>>]<[[-]
          Assignment to output:
          <<<<[-]
             copy ch to m6
             <[->>>>>>>>+<<<<<<<<]>>>>>>>>[-<<<<<<<<+>>>>>>+>>]
             Add 55 to m7
             +++++[-<+++++++++++>]<
            subtract m7 from m6
            [-<->]
            Add 16 to m7
            >++++[-<++++>]<
           add m6 times m7 to output
           <[->[->+<]>[-<+<<<<<<+>>>>>>>]<<]>[-]
          inc mode
          <<<<<+>>>]
      else (m4)
      ]<[[-]
           Add 97 to m8
           >>>>>++++++++[-<++++++++++++>]<+
           copy ch to m9
           <<<<<<<<[->>>>>>>>>>+<<<<<<<<<<]>>>>>>>>>>[-<<<<<<<<<<+>>>>>>>>>+>]
          m8 less than or equal m9 to m7
          <[->>+<<<[->>+<<]>>[-[-<<+>>]>-<]<]>>[-<<+>>]<<[-]<<+>[[-]<->]
           copy ch to m9
           <<<<<<<<[->>>>>>>>>>+<<<<<<<<<<]>>>>>>>>>>[-<<<<<<<<<<+>>>>>>>>>+>]
           Add 102 to m10
           >++++++++++[-<++++++++++>]<++
          m9 less than or equal m10 to m8
          [->>+<<<[->>+<<]>>[-[-<<+>>]>-<]<]>>[-<<+>>]<<[-]<<+>[[-]<->]
         and m7 and m8 to m6
         <<[[-]>[-<<+>>]<]>[-]
        if m6 (m5)
        <<<+>[[-]<-
           copy mode to m7
           <<<[->>>>>>+<<<<<<]>>>>>>[-<<<<<<+>>>>>+>]
          if m7 (m6)
          <<+>[[-]<-
               copy ch to m7
               <<<<<<[->>>>>>>>>+<<<<<<<<<]>>>>>>>>>[-<<<<<<<<<+>>>>>>>+>>]
               Add 87 to m8
               +++++++[-<++++++++++++>]<+++
              subtract m8 from m7
              [-<->]
              copy output to m7
              <<<<<<<[->>>>>>>+<<<<<<<]>>>>>>>[-<<<<<<<+>>>>>>+>]
            Write m7
            <.[-]
            dec mode
            <<<<<-
          else (m6)
          >>>>>]<[[-]
            Assignment to output:
            <<<<<[-]
               copy ch to m7
               <[->>>>>>>>>+<<<<<<<<<]>>>>>>>>>[-<<<<<<<<<+>>>>>>>+>>]
               Add 87 to m8
               +++++++[-<++++++++++++>]<+++
              subtract m8 from m7
              [-<->]
              Add 16 to m8
              >++++[-<++++>]<
             add m7 times m8 to output
             <[->[->+<]>[-<+<<<<<<<+>>>>>>>>]<<]>[-]
            inc mode
            <<<<<<+>>>>]
        else (m5)
        ]<[[-]
             copy ch to m7
             <<<<<[->>>>>>>>+<<<<<<<<]>>>>>>>>[-<<<<<<<<+>>>>>>>+>]
             Add 59 to m8
             >+++++++[-<++++++++>]<+++
            m7 equal m8 to m6
            [->>+<<<[->>+<<]>>[-[-<<+>>]>-<]<]>>[-<<+>>]<<[-<+>]<<+>[[-]<->]
             copy ch to m7
             <<<<<<<[->>>>>>>>+<<<<<<<<]>>>>>>>>[-<<<<<<<<+>>>>>>>+>]
             Add 35 to m8
             >+++++[-<+++++++>]<
            m7 equal m8 to m6
            [->>+<<<[->>+<<]>>[-[-<<+>>]>-<]<]>>[-<<+>>]<<[-<+>]<<+>[[-]<->]
          if m6
          <[[-]
            Assignment to ch:
            <<<<<<[-]
             Read into ch
             ,
              copy ch to m7
              [->>>>>>>>+<<<<<<<<]>>>>>>>>[-<<<<<<<<+>>>>>>>+>]
               copy ch to m9
               <<<<<<<<[->>>>>>>>>>+<<<<<<<<<<]>>>>>>>>>>[-<<<<<<<<<<+>>>>>>>>>+>]
               Add 10 to m10
               ++++++++++
              m9 not equal m10 to m8
              [->>+<<<[->>+<<]>>[-[-<<+>>]>-<]<]>>[-<<+>>]<<[-<<+>>]<[-<+>]
             and m7 and m8 to m6
             <<[[-]>[-<<+>>]<]>[-]
            while m6
            <<[[-]
              Assignment to ch:
              <<<<<<[-]
               Read into ch
               ,
              copy ch to m7
              [->>>>>>>>+<<<<<<<<]>>>>>>>>[-<<<<<<<<+>>>>>>>+>]
               copy ch to m9
               <<<<<<<<[->>>>>>>>>>+<<<<<<<<<<]>>>>>>>>>>[-<<<<<<<<<<+>>>>>>>>>+>]
               Add 10 to m10
               ++++++++++
              m9 not equal m10 to m8
              [->>+<<<[->>+<<]>>[-[-<<+>>]>-<]<]>>[-<<+>>]<<[-<<+>>]<[-<+>]
             and m7 and m8 to m6
             <<[[-]>[-<<+>>]<]>[-]<<]]<]<]<]
    Assignment to ch:
    <<<[-]
     Read into ch
     ,
   copy ch to m3
   [->>>>+<<<<]>>>>[-<<<<+>>>+>]<]