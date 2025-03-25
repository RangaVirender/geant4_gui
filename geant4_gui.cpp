class MyMainFrame : public TGMainFrame
{
    private:
    TGTextButton *check_geant4_button; // Button for checking geant4 installation
    TGTextButton *cmake_button; // Button for cmake
    TGTextButton *make_button; // Button for make
    TGTextButton *run_sim_button; // Button for running simulation
    TGTextButton *exit_button;  // Button for exiting the application
    TGTextButton *load_log_button;  // Button for loading log.txt
    TGTextButton *load_instrxn_button;  // Button for loading instruction.txt
    TGTextView   *text_output;    // Text output field
    TGGroupFrame *grid_frame_1; //grid 1 
    TGGroupFrame *grid_frame_2; //grid 2 
    TGGroupFrame *grid_frame_3; //grid 3 

    public:
    MyMainFrame(const TGWindow *p, UInt_t w, UInt_t h);
    virtual ~MyMainFrame();
    void geant4_button_clicked(); // Action for "Click Me" button
    void cmake_button_clicked(); // Action for "Click Me" button
    void make_button_clicked(); // Action for "Click Me" button
    void run_sim_button_clicked(); // Action for "Click Me" button
    void exit_button_clicked();  // Action for "Exit" button
    void load_instrxn_button_clicked();
    void load_log_button_clicked();
    void LoadFile(const char *filename);  // Function to load file into TGTextView
    void update_text_output();  // Function to update TGTextView in real time
    virtual void CloseWindow();  // Properly handle window close
};


MyMainFrame::MyMainFrame(const TGWindow *p, UInt_t w, UInt_t h) : TGMainFrame(p, w, h) 
{
    // kLHintsCenterX: Aligns the widget horizontally to the center of its parent frame.
    //5, 5, 5, 5: Margins around the button in the order—left, right, top, bottom (in pixels).

    // Layout 3: Grid-like arrangement of buttons
    grid_frame_1 = new TGGroupFrame(this, "Useful Checks", kHorizontalFrame);
    
    //'this' Refers to the parent frame or window that the composite frame belongs to. 
    //It likely represents the current instance of the main frame or another GUI container.
    //70, 10: These are the width and height of the composite frame, in pixels.
    //kHorizontalFrame: A flag indicating how the frame organizes its child components. In this case, it arranges them horizontally.

    // Create "Check Geant4" button
    check_geant4_button = new TGTextButton(grid_frame_1, "Check Geant4");
    check_geant4_button->Connect("Clicked()", "MyMainFrame", this, "geant4_button_clicked()"); // Connect to click handler
    
     // Create "Load Instructions" button
    load_instrxn_button = new TGTextButton(grid_frame_1, "Load Instructions");
    load_instrxn_button->Connect("Clicked()", "MyMainFrame", this, "load_instrxn_button_clicked()"); // Connect to exit handler
    
    // Create "Load LOG file" button
    load_log_button = new TGTextButton(grid_frame_1, "Load LOG file");
    load_log_button->Connect("Clicked()", "MyMainFrame", this, "load_log_button_clicked()"); // Connect to exit handler
 
    grid_frame_1->AddFrame(check_geant4_button, new TGLayoutHints(kLHintsCenterX, 5, 5, 5, 0));
    grid_frame_1->AddFrame(load_instrxn_button, new TGLayoutHints(kLHintsCenterX, 5, 5, 5, 0));
    grid_frame_1->AddFrame(load_log_button, new TGLayoutHints(kLHintsCenterX, 5, 5, 5, 0));
    AddFrame(grid_frame_1, new TGLayoutHints(kLHintsExpandX, 5, 5, 5, 5));

    grid_frame_3 = new TGGroupFrame(this, "Primary functions", kHorizontalFrame);

    // Create cmake button
    cmake_button = new TGTextButton(grid_frame_3, "Run CMAKE");
    cmake_button->Connect("Clicked()", "MyMainFrame", this, "cmake_button_clicked()"); // Connect to click handler
    
    // Create make button
    make_button = new TGTextButton(grid_frame_3, "Run MAKE");
    make_button->Connect("Clicked()", "MyMainFrame", this, "make_button_clicked()"); // Connect to click handler
 
    // Create run simulation button
    run_sim_button = new TGTextButton(grid_frame_3, "Run Simulation");
    run_sim_button->Connect("Clicked()", "MyMainFrame", this, "run_sim_button_clicked()"); // Connect to click handler
    
    grid_frame_3->AddFrame(cmake_button, new TGLayoutHints(kLHintsCenterX, 5, 5, 5, 5));
    grid_frame_3->AddFrame(make_button, new TGLayoutHints(kLHintsCenterX, 5, 5, 5, 5));
    grid_frame_3->AddFrame(run_sim_button, new TGLayoutHints(kLHintsCenterX, 5, 5, 5, 5));
    AddFrame(grid_frame_3, new TGLayoutHints(kLHintsExpandX, 5, 5, 5, 5));

    // Create "Exit" button
    exit_button = new TGTextButton(this, "Exit");
    exit_button->Connect("Clicked()", "MyMainFrame", this, "exit_button_clicked()"); // Connect to exit handler
    AddFrame(exit_button, new TGLayoutHints(kLHintsCenterX, 5, 5, 5, 5));
   
    // Create text output field
    text_output = new TGTextView(this, 400, 200); // 200x100 pixels size
    AddFrame(text_output, new TGLayoutHints(kLHintsExpandX | kLHintsExpandY, 10, 10, 0, 10));

    // Set up the main frame
    SetWindowName("CERN-ROOT based GUI for Geant4 by V. Ranga (2025)");
    MapSubwindows();
    Resize(GetDefaultSize());  // Automatically fit all widgets
    MapWindow();
}

MyMainFrame::~MyMainFrame() {
    // Cleanup dynamically allocated objects
    RemoveFrame(cmake_button);          delete cmake_button;
    RemoveFrame(make_button);           delete make_button;
    RemoveFrame(run_sim_button);        delete run_sim_button;
    RemoveFrame(exit_button);           delete exit_button;
    RemoveFrame(load_instrxn_button);   delete load_instrxn_button;
    RemoveFrame(load_log_button);       delete load_log_button;
    RemoveFrame(text_output);           delete text_output;
    
    Cleanup();
}

// Function to update TGTextView in real time
void MyMainFrame::update_text_output()
{
    text_output->Update();  // Force immediate UI refresh
    gSystem->ProcessEvents(); // Process pending UI events
}

// Function to load a file into TGTextView
void MyMainFrame::LoadFile(const char *filename)
{
    text_output->Clear();
    std::ifstream file(filename);
    if (!file) 
    {
       text_output->AddLine("Error: Unable to open file!");
       return;
    }

    std::string line;
    while (std::getline(file, line)) 
    {
       text_output->AddLine(line.c_str());
    }
    file.close();
}


void MyMainFrame::load_instrxn_button_clicked()
{
    LoadFile("instructions.txt");
}

void MyMainFrame:: load_log_button_clicked()
{
    LoadFile("log.txt");
}

void MyMainFrame::geant4_button_clicked()
{   
   
   text_output->AddLine("Finding Geant4..."); update_text_output();
    
    int geant4_status = gSystem->Exec("geant4-config --version  > log.txt 2>&1");
    
    if(geant4_status != 0)
     {
       text_output->AddLine("Cannot find Geant4. Please source geant4.sh"); update_text_output();
        return;
     }
     else 
     {
        TString geant4_version = gSystem->GetFromPipe("geant4-config --version");
        TString print_geant4_version_command = "Found Geant4 version " + geant4_version + " Click on Run CMAKE to proceed.";
        text_output->AddLine(print_geant4_version_command); update_text_output();
     }    
}


void MyMainFrame::cmake_button_clicked()
{   
   text_output->AddLine("Running CMAKE..."); update_text_output();
    
    int cmake_status = gSystem->Exec("cd geant4/build && rm -r *  && cmake ../source >> ../../log.txt 2>&1");// > to rewrite log file
    if(cmake_status != 0)
     {
       text_output->AddLine("Error: CMAKE failed. Check log.txt"); update_text_output();
        return;
     }
     else 
     {
       text_output->AddLine("CMAKE completed successfully. Click on Run MAKE to proceed."); update_text_output();
     }    
}
//2>&1 is a shell redirection operator. It redirects stderr (error output, file descriptor 2) to
//stdout (standard output, file descriptor 1) so that both standard output and error messages appear in the same stream.
        
void MyMainFrame::make_button_clicked()
{
   text_output->AddLine("Running MAKE using 4 cores..."); update_text_output();
    
    int make_status = gSystem->Exec("cd geant4/build && make -j4 >> ../../log.txt 2>&1");// >> append to log file
    if(make_status != 0)
     {
        text_output->AddLine("Error: MAKE failed. Check log.txt"); update_text_output();
        return;
     }
     else 
     {
       text_output->AddLine("MAKE completed successfully. Click on Run Simulation to proceed."); update_text_output();
     }
}

void MyMainFrame::run_sim_button_clicked()
{
   text_output->AddLine("Started..."); update_text_output();
   text_output->AddLine("Grabbing executable file name..."); update_text_output();
   
   // Execute the shell command and store output
   TString exec_name = gSystem->GetFromPipe("grep 'Built target' log.txt | awk '{print $4}'");
   
   // Print the extracted executable name
   // Construct a shell command using the extracted executable name
   TString print_exe_name_command = "Ecexutable file name is: " + exec_name;
   text_output->AddLine(print_exe_name_command); update_text_output();
   text_output->AddLine("Running simulation..."); update_text_output();     
   
   // Construct a shell command using the extracted executable name
   TString exe_command = "cd geant4/build && ./" + exec_name + " >> ../../log.txt 2>&1";
   
   // Execute the command
   int sim_status = gSystem->Exec(exe_command);
   
   // Check execution result
   cout << "Execution returned: " << sim_status << endl;
   
   if (sim_status != 0)
    {
       text_output->AddLine("Error: Simulation failed. Check log.txt"); update_text_output();
       return;
    }
    text_output->AddLine("Run successful"); update_text_output();
}


void MyMainFrame::exit_button_clicked()
{
    text_output->AddLine("Exiting application..."); // Add exit message
    gApplication->Terminate(0); // Gracefully exit the application
}

// Properly handle window close
void MyMainFrame::CloseWindow() {
    std::cout << "Closing application...\n";
    gApplication->Terminate(0);  // Stops the ROOT event loop
}

int geant4_gui() {
    TApplication app("ROOT Application", 0, nullptr);
    //0: Represents the argc parameter (argument count). Since no command-line arguments are being passed, this value is set to 0.
    //nullptr: Represents the argv parameter (argument vector). Since there are no command-line arguments, it is set to nullptr (null pointer).
    MyMainFrame *mainFrame = new MyMainFrame(gClient->GetRoot(), 700, 700); // Specifies the width and height of the MyMainFrame window in pixels.
    app.Run();

    // Delete main frame after application ends
    delete mainFrame;
    return 0;
}
