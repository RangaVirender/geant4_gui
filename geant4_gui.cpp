class MyMainFrame : public TGMainFrame
{
    private:
    TGTextButton  *check_geant4_button; // Button for checking geant4 installation
    
    TGButtonGroup *vis_mode_button_group;
    TGRadioButton *vis_mode_ON_button;
    TGRadioButton *vis_mode_OFF_button;
    
    TGButtonGroup *al_cover_button_group;
    TGRadioButton *al_cover_ON_button;
    TGRadioButton *al_cover_OFF_button;
    
    TGComboBox    *select_rad_nuclei_cbox; // List for selecting detector material
    TGComboBox    *select_rad_source_cbox; // List for selecting detector material
    TGLabel       *select_rad_source_label;

    TGNumberEntry *particle_energy_entry;
    TGLabel       *particle_energy_label;

    TGComboBox    *select_det_mat_cbox; // List for selecting detector material
    TGLabel       *select_det_mat_label;
    
    TGComboBox    *select_det_shape_cbox; // List for selecting detector material
    TGLabel       *select_det_shape_label;
     
    TGNumberEntry *no_of_events_entry;
    TGLabel       *no_of_events_label;

    TGNumberEntry *no_of_threads_entry;
    TGLabel       *no_of_threads_label;
    
    TGNumberEntry *det_inner_radius_entry;
    TGLabel       *det_inner_radius_label;

    TGNumberEntry *det_outer_radius_entry;
    TGLabel       *det_outer_radius_label;
    
    TGNumberEntry *det_length_entry;
    TGLabel       *det_length_label;
    
    TGNumberEntry *al_thickness_entry;
    TGLabel       *al_thickness_label;
    
    TGNumberEntry *al_gap_entry;
    TGLabel       *al_gap_label;

    TGNumberEntry *det_source_dis_entry;
    TGLabel       *det_source_dis_label;

    TGTextButton  *parameters_help_button; // Button for cmake
    
    TGTextButton  *clear_build_button; // Button for cmake
    TGTextButton  *cmake_button; // Button for cmake
    TGTextButton  *make_button; // Button for make
    TGTextButton  *run_sim_button; // Button for running simulation
    
    TGTextButton  *plot_spec_button; // Button for running simulation
    
    TGLabel       *get_counts_label;
    TGTextButton  *get_counts_button; // Button for running simulation
    TGNumberEntry *get_counts_entry; // Button for running simulation
    
    TGTextButton  *exit_button;  // Button for exiting the application
   
    TGTextButton  *load_instrxn_button;  // Button for loading instruction.txt
    
    
    
    TGGroupFrame  *global_frame;
    
    TGGroupFrame  *det_frame;
    
    TGGroupFrame  *grid_frame_1; //grid 1 
    TGGroupFrame  *grid_frame_2; //grid 2 
    TGGroupFrame  *grid_frame_3; //grid 3 
    TGGroupFrame  *grid_frame_4; //grid 3 
    
    TString        vis_mode_string;
    
    TString        det_mat_string;
    TString        det_shape_string;
    TString        det_inner_radius_string;
    TString        det_outer_radius_string;
    
    TString        al_cover_status_string;
    TString        al_thickness_string;
    double         al_thickness_double;
    TString        al_gap_string;
    double         al_gap_double;
    
    TString        det_length_string;
    TString        det_source_dis_string;
   
    TString        rad_source_string;
    TString        rad_source_data_string;
    TString        rad_nuclei_string;
    double         rad_particle_energy_double;
    int            rad_source_int;
    int            rad_nuclei_int;
    int            det_mat_int;
    int            det_shape_int;
    TGLabel       *label;
    int            no_of_events_int;
    TString        no_of_events_string;
    TString        no_of_threads_string;
    int            no_of_threads_int;
    int            no_of_cores_int;
    
    TString        no_of_cores_string;
    double         det_inner_radius_double;
    double         det_outer_radius_double;
    double         det_length_double;
    double         det_source_dis_double;
    int            frame;
    
    TH1D  *h1;
    TFile *f1;

    public:
    MyMainFrame(const TGWindow *p, UInt_t w, UInt_t h);
    virtual ~MyMainFrame();
    void source_sh_file_button_clicked(); // Action for "Click Me" button
    void check_geant4_button_clicked(); // Action for "Click Me" button
    void parameters_help_button_clicked();
    void al_cover_button_clicked(); // Action for "Click Me" button
    void clear_build_button_clicked(); // Action for "Click Me" button
    void cmake_button_clicked(); // Action for "Click Me" button
    void make_button_clicked(); // Action for "Click Me" button
    void run_sim_button_clicked(); // Action for "Click Me" button
    void stop_sim_button_clicked(); // Action for "Click Me" button
    void plot_spec_button_clicked(); // Action for "Click Me" button
    void get_counts_button_clicked(); // Action for "Click Me" button
    void exit_button_clicked();  // Action for "Exit" button
    void det_shape_selected(Int_t);
    void rad_source_selected(Int_t);
    void load_instrxn_button_clicked();
    void LoadFile(const char *filename);  // Function to load file into TGTextView
    void UpdateAnimation();
    virtual void CloseWindow();  // Properly handle window close
    TString       pwd_path;
    
};


MyMainFrame::MyMainFrame(const TGWindow *p, UInt_t w, UInt_t h) : TGMainFrame(p, w, h) 
{
    // kLHintsCenterX: Aligns the widget horizontally to the center of its parent frame.
    //5, 5, 5, 5: Margins around the button in the order—left, right, top, bottom (in pixels).

    
    //'this' Refers to the parent frame or window that the composite frame belongs to. 
    //It likely represents the current instance of the main frame or another GUI container.
    //70, 10: These are the width and height of the composite frame, in pixels.
    //kHorizontalFrame: A flag indicating how the frame organizes its child components. In this case, it arranges them horizontally.

    
    global_frame = new TGGroupFrame(this, "global", kHorizontalFrame);

   
    grid_frame_1 = new TGGroupFrame(global_frame, "Useful Checks", kVerticalFrame);
    
    check_geant4_button = new TGTextButton(grid_frame_1, "Check Geant4");
    check_geant4_button->Connect("Clicked()", "MyMainFrame", this, "check_geant4_button_clicked()"); // Connect to click handler
    
    load_instrxn_button = new TGTextButton(grid_frame_1, "Load Instructions");
    load_instrxn_button->Connect("Clicked()", "MyMainFrame", this, "load_instrxn_button_clicked()"); // Connect to exit handler
    
    grid_frame_1->AddFrame(check_geant4_button, new TGLayoutHints(kLHintsExpandX, 5, 5, 5, 0));
    grid_frame_1->AddFrame(load_instrxn_button, new TGLayoutHints(kLHintsExpandX, 5, 5, 5, 0));
    global_frame->AddFrame(grid_frame_1, new TGLayoutHints(kLHintsExpandX, 5, 5, 5, 5));

    grid_frame_2 = new TGGroupFrame(global_frame, "Simulation Parameters", kVerticalFrame);
    det_frame = new TGGroupFrame(global_frame, "Detector", kVerticalFrame);
    
    vis_mode_button_group = new TGButtonGroup(grid_frame_2, "Visualisation Mode");
    vis_mode_ON_button  = new TGRadioButton(vis_mode_button_group, "ON");
    vis_mode_OFF_button = new TGRadioButton(vis_mode_button_group, "OFF");
    vis_mode_ON_button->SetState(kButtonDown); // Marks it as selected

    parameters_help_button = new TGTextButton(grid_frame_2, "Help");
    parameters_help_button->Connect("Clicked()", "MyMainFrame", this, "parameters_help_button_clicked()"); // Connect to click handler
    
    select_rad_source_label = new TGLabel(grid_frame_2, "Radiation source");
    select_rad_source_cbox = new TGComboBox(grid_frame_2, -1);
    select_rad_source_cbox->AddEntry("Radioactive nuclei", 1);
    select_rad_source_cbox->AddEntry("Gamma", 2);
    select_rad_source_cbox->AddEntry("Proton", 3);
    select_rad_source_cbox->Connect("Selected(Int_t)", "MyMainFrame", this, "rad_source_selected(Int_t)");
    select_rad_source_cbox->Resize(200, 25); // Resize the text entry field

    select_rad_nuclei_cbox = new TGComboBox(grid_frame_2, -1);
    select_rad_nuclei_cbox->AddEntry("Cs137", 1);
    select_rad_nuclei_cbox->AddEntry("Co60", 2);
    select_rad_nuclei_cbox->AddEntry("Na22", 3);
    select_rad_nuclei_cbox->AddEntry("Ba133", 4);
    select_rad_nuclei_cbox->Select(1);
    select_rad_nuclei_cbox->Resize(100, 25); // Resize the text entry field

    particle_energy_label = new TGLabel(grid_frame_2, "Particle energy(keV)");
    particle_energy_entry = new TGNumberEntry(grid_frame_2, 662, 5, -1, TGNumberFormat::kNESReal);//default value, max digits, ID 
    particle_energy_entry->SetLimits(TGNumberFormat::kNELLimitMinMax, 0.0, 1e5);
    
    select_det_shape_label = new TGLabel(det_frame, "Detector shape");
    select_det_shape_cbox = new TGComboBox(det_frame, -1);
    select_det_shape_cbox->AddEntry("Cylinder", 1);
    select_det_shape_cbox->AddEntry("Box", 2);
    select_det_shape_cbox->Connect("Selected(Int_t)", "MyMainFrame", this, "det_shape_selected(Int_t)");

    select_det_shape_cbox->Resize(250, 25); // Resize the text entry field
   
    det_inner_radius_label = new TGLabel(det_frame, "Detector inner radius(cm)");
    det_inner_radius_entry = new TGNumberEntry(det_frame, 0, 5, -1, TGNumberFormat::kNESReal);//default value, max digits, ID 
    det_inner_radius_entry->SetLimits(TGNumberFormat::kNELLimitMinMax, 0.0, 1e5);
    
    det_outer_radius_label = new TGLabel(det_frame, "Detector outer radius(cm)");
    det_outer_radius_entry = new TGNumberEntry(det_frame, 1, 5, -1, TGNumberFormat::kNESReal);//default value, max digits, ID 
    det_outer_radius_entry->SetLimits(TGNumberFormat::kNELLimitMinMax, 0.0, 1e5);
    
    det_length_label = new TGLabel(det_frame, "Detector length(cm)");
    det_length_entry = new TGNumberEntry(det_frame, 1, 5, -1, TGNumberFormat::kNESReal);//default value, max digits, ID 
    det_length_entry->SetLimits(TGNumberFormat::kNELLimitMinMax, 0.0, 1e5);
    
    // Create a button group
    al_cover_button_group = new TGButtonGroup(det_frame, "Aluminium casing");
    // Add radio buttons to the group
    al_cover_ON_button  = new TGRadioButton(al_cover_button_group, "ON");
    al_cover_OFF_button = new TGRadioButton(al_cover_button_group, "OFF");
    al_cover_ON_button->SetState(kButtonDown); // Marks it as selected
    al_cover_status_string = "al_cover_ON";

    al_cover_ON_button->Connect("Clicked()", "MyMainFrame", this, "al_cover_button_clicked()"); // Connect to click handler
    al_cover_OFF_button->Connect("Clicked()", "MyMainFrame", this, "al_cover_button_clicked()"); // Connect to click handler

    al_thickness_label = new TGLabel(det_frame, "Aluminium Thickness(mm)");
    al_thickness_entry = new TGNumberEntry(det_frame, 1, 5, -1, TGNumberFormat::kNESReal);//default value, max digits, ID 
    al_thickness_entry->SetLimits(TGNumberFormat::kNELLimitMinMax, 0.0, 1e5);
    
    al_gap_label = new TGLabel(det_frame, "Aluminium-Crystal gap(mm)");
    al_gap_entry = new TGNumberEntry(det_frame, 1, 5, -1, TGNumberFormat::kNESReal);//default value, max digits, ID 
    al_gap_entry->SetLimits(TGNumberFormat::kNELLimitMinMax, 0.0, 1e5);
    
    det_source_dis_label = new TGLabel(det_frame, "Detector source distance");
    det_source_dis_entry = new TGNumberEntry(det_frame, 1, 5, -1, TGNumberFormat::kNESReal);//default value, max digits, ID 
    det_source_dis_entry->SetLimits(TGNumberFormat::kNELLimitMinMax, 0.0, 1e5);
    
    select_det_mat_label = new TGLabel(det_frame, "Detector material");
    select_det_mat_cbox = new TGComboBox(det_frame, -1);//"Select Detector Material");
    select_det_mat_cbox->AddEntry("NaI:Tl", 1);
    select_det_mat_cbox->AddEntry("LaBr3:Ce", 2);
    select_det_mat_cbox->AddEntry("CeBr3", 3);
    select_det_mat_cbox->AddEntry("HPGe", 4);
    select_det_mat_cbox->AddEntry("BGO", 5);
    // Set default entry (e.g., "Option 2" with ID = 2)
    select_det_mat_cbox->Select(1);
    select_det_mat_cbox->Resize(100, 25); // Resize the text entry field

    no_of_threads_label = new TGLabel(grid_frame_2, "CPU Cores");
    no_of_threads_entry = new TGNumberEntry(grid_frame_2, 4, 2, -1, TGNumberFormat::kNESInteger);//default value, max digits, ID 
    // no_of_events_entry->SetText("10"); // Set default text
    
    no_of_cores_string = gSystem->GetFromPipe("grep '^core id' /proc/cpuinfo | sort -u | wc -l");
    //cout << "No of cores in CPU: " << no_of_cores_string << endl;
    no_of_cores_int = no_of_cores_string.Atoi();
    no_of_threads_entry->SetLimits(TGNumberFormat::kNELLimitMinMax, 1, no_of_cores_int);
   
    no_of_events_label = new TGLabel(grid_frame_2, "No of events");
    no_of_events_entry = new TGNumberEntry(grid_frame_2, 1, 9, -1, TGNumberFormat::kNESInteger);//default value, max digits, ID 
    // no_of_events_entry->SetText("10"); // Set default text
    no_of_events_entry->SetLimits(TGNumberFormat::kNELLimitMinMax, 1, 1e8);
   
    grid_frame_2->AddFrame(vis_mode_button_group, new TGLayoutHints(kLHintsExpandX, 5, 5, 5, 0));
    grid_frame_2->AddFrame(no_of_threads_label, new TGLayoutHints(kLHintsExpandX, 5, 5, 5, 0));
    grid_frame_2->AddFrame(no_of_threads_entry, new TGLayoutHints(kLHintsExpandX, 5, 5, 5, 0));
    grid_frame_2->AddFrame(no_of_events_label, new TGLayoutHints(kLHintsExpandX, 5, 5, 5, 0));
    grid_frame_2->AddFrame(no_of_events_entry, new TGLayoutHints(kLHintsExpandX, 5, 5, 5, 0));
    grid_frame_2->AddFrame(select_rad_source_label, new TGLayoutHints(kLHintsExpandX, 5, 5, 5, 0));
    grid_frame_2->AddFrame(select_rad_source_cbox, new TGLayoutHints(kLHintsExpandX, 5, 5, 5, 0));
    grid_frame_2->AddFrame(select_rad_nuclei_cbox, new TGLayoutHints(kLHintsExpandX, 5, 5, 5, 0));
    
    grid_frame_2->AddFrame(particle_energy_label, new TGLayoutHints(kLHintsExpandX, 5, 5, 5, 0));
    grid_frame_2->AddFrame(particle_energy_entry, new TGLayoutHints(kLHintsExpandX, 5, 5, 5, 0));
    grid_frame_2->AddFrame(parameters_help_button, new TGLayoutHints(kLHintsExpandX, 5, 5, 5, 0));
    
    /////////////////////////////
    select_rad_source_cbox->Select(1);
    //////////////////////////////////
    det_frame->AddFrame(select_det_shape_label, new TGLayoutHints(kLHintsExpandX, 5, 5, 5, 0));
    det_frame->AddFrame(select_det_shape_cbox, new TGLayoutHints(kLHintsExpandX, 5, 5, 5, 0));
    det_frame->AddFrame(det_length_label, new TGLayoutHints(kLHintsExpandX, 5, 5, 5, 0));
    det_frame->AddFrame(det_length_entry, new TGLayoutHints(kLHintsExpandX, 5, 5, 5, 0));
    det_frame->AddFrame(det_inner_radius_label, new TGLayoutHints(kLHintsExpandX, 5, 5, 5, 0));
    det_frame->AddFrame(det_inner_radius_entry, new TGLayoutHints(kLHintsExpandX, 5, 5, 5, 0));
    det_frame->AddFrame(det_outer_radius_label, new TGLayoutHints(kLHintsExpandX, 5, 5, 5, 0));
    det_frame->AddFrame(det_outer_radius_entry, new TGLayoutHints(kLHintsExpandX, 5, 5, 5, 0));
    
    det_frame->AddFrame(al_cover_button_group, new TGLayoutHints(kLHintsExpandX, 5, 5, 5, 0));
    det_frame->AddFrame(al_thickness_label, new TGLayoutHints(kLHintsExpandX, 5, 5, 5, 0));
    det_frame->AddFrame(al_thickness_entry, new TGLayoutHints(kLHintsExpandX, 5, 5, 5, 0));
    det_frame->AddFrame(al_gap_label, new TGLayoutHints(kLHintsExpandX, 5, 5, 5, 0));
    det_frame->AddFrame(al_gap_entry, new TGLayoutHints(kLHintsExpandX, 5, 5, 5, 0));
    
    det_frame->AddFrame(det_source_dis_label, new TGLayoutHints(kLHintsExpandX, 5, 5, 5, 0));
    det_frame->AddFrame(det_source_dis_entry, new TGLayoutHints(kLHintsExpandX, 5, 5, 5, 0));
     
    det_frame->AddFrame(select_det_mat_label, new TGLayoutHints(kLHintsExpandX, 5, 5, 5, 0));
    det_frame->AddFrame(select_det_mat_cbox, new TGLayoutHints(kLHintsExpandX, 5, 5, 5, 0));
    
    global_frame->AddFrame(grid_frame_2, new TGLayoutHints(kLHintsExpandX, 5, 5, 5, 5));

    global_frame->AddFrame(det_frame, new TGLayoutHints(kLHintsExpandX, 5, 5, 5, 5));
//*******************    
    select_det_shape_cbox->Select(1);
//*******************

    grid_frame_3 = new TGGroupFrame(global_frame, "Primary functions", kVerticalFrame);
    // Create clear build button
    clear_build_button = new TGTextButton(grid_frame_3, "Clear build folder");
    clear_build_button->Connect("Clicked()", "MyMainFrame", this, "clear_build_button_clicked()"); // Connect to click handler
    
    // Create cmake button
    cmake_button = new TGTextButton(grid_frame_3, "Run CMAKE");
    cmake_button->Connect("Clicked()", "MyMainFrame", this, "cmake_button_clicked()"); // Connect to click handler
    
    // Create make button
    make_button = new TGTextButton(grid_frame_3, "Run MAKE");
    make_button->Connect("Clicked()", "MyMainFrame", this, "make_button_clicked()"); // Connect to click handler
    
    // Create run simulation button
    run_sim_button = new TGTextButton(grid_frame_3, "Run Simulation");
    run_sim_button->Connect("Clicked()", "MyMainFrame", this, "run_sim_button_clicked()"); // Connect to click handler
    
    // Create stop simulation button
  //   stop_sim_button = new TGTextButton(grid_frame_3, "Stop Simulation");
   //  stop_sim_button->Connect("Clicked()", "MyMainFrame", this, "stop_sim_button_clicked()"); // Connect to click handler

    grid_frame_3->AddFrame(clear_build_button, new TGLayoutHints(kLHintsExpandX, 5, 5, 5, 5));
    grid_frame_3->AddFrame(cmake_button, new TGLayoutHints(kLHintsExpandX, 5, 5, 5, 5));
    grid_frame_3->AddFrame(make_button, new TGLayoutHints(kLHintsExpandX, 5, 5, 5, 5));
    grid_frame_3->AddFrame(run_sim_button, new TGLayoutHints(kLHintsExpandX, 5, 5, 5, 5));
    global_frame->AddFrame(grid_frame_3, new TGLayoutHints(kLHintsExpandX, 5, 5, 5, 5));
 
    grid_frame_4 = new TGGroupFrame(global_frame, "Analysis", kVerticalFrame);
    label = new TGLabel(grid_frame_4, "........................");
    // Set the text color to red
    label->SetTextColor(TColor::RGB2Pixel(255, 0, 0));

    
    plot_spec_button = new TGTextButton(grid_frame_4, "Plot spectrum");
    plot_spec_button->Connect("Clicked()", "MyMainFrame", this, "plot_spec_button_clicked()"); // Connect to exit handler
    
    get_counts_label = new TGLabel(grid_frame_4, "Get counts at energy(keV)");
    get_counts_entry = new TGNumberEntry(grid_frame_4, 1, 5, -1, TGNumberFormat::kNESInteger);//default value, max digits, ID 
    get_counts_entry->SetLimits(TGNumberFormat::kNELLimitMinMax, 0, 5e3);
    get_counts_entry->Resize(200, 25); // Resize the text entry field
    
    get_counts_button = new TGTextButton(grid_frame_4, "Get counts");
    get_counts_button->Connect("Clicked()", "MyMainFrame", this, "get_counts_button_clicked()"); // Connect to exit handler
    
    // Create "Exit" button
    exit_button = new TGTextButton(grid_frame_4, "Exit");
    exit_button->Connect("Clicked()", "MyMainFrame", this, "exit_button_clicked()"); // Connect to exit handler
    

    grid_frame_4->AddFrame(label, new TGLayoutHints(kLHintsExpandX, 5, 5, 5, 5));
    grid_frame_4->AddFrame(plot_spec_button, new TGLayoutHints(kLHintsExpandX, 5, 5, 5, 5));
    grid_frame_4->AddFrame(get_counts_label, new TGLayoutHints(kLHintsExpandX, 5, 5, 5, 5));
    grid_frame_4->AddFrame(get_counts_entry, new TGLayoutHints(kLHintsExpandX, 5, 5, 5, 5));
    grid_frame_4->AddFrame(get_counts_button, new TGLayoutHints(kLHintsExpandX, 5, 5, 5, 5));
    grid_frame_4->AddFrame(exit_button, new TGLayoutHints(kLHintsExpandX, 5, 5, 5, 5));
    global_frame->AddFrame(grid_frame_4, new TGLayoutHints(kLHintsExpandX, 5, 5, 5, 5));
    

    AddFrame(global_frame, new TGLayoutHints(kLHintsExpandX, 5, 5, 5, 5));
       
    // Set up the main frame
    SetWindowName("CERN-ROOT based GUI for Geant4 by V. Ranga (2025)");
    MapSubwindows();
    Resize(GetDefaultSize());  // Automatically fit all widgets
    MapWindow();
}

MyMainFrame::~MyMainFrame() {
    // Cleanup dynamically allocated objects
    RemoveFrame(clear_build_button);    delete clear_build_button;
    RemoveFrame(cmake_button);          delete cmake_button;
    RemoveFrame(make_button);           delete make_button;
    RemoveFrame(run_sim_button);        delete run_sim_button;
    RemoveFrame(exit_button);           delete exit_button;
    RemoveFrame(load_instrxn_button);   delete load_instrxn_button;
    
    Cleanup();
}

void MyMainFrame::parameters_help_button_clicked()
{
  cout << "\033[32m" 
       << "HELP" << endl
       << "HELP content goes here "
       << "\033[0m" << endl;   
  return;
}

void MyMainFrame::rad_source_selected(Int_t selected_item_id)
{
    switch(selected_item_id)
    {
    case 1: //radioactive nuclei selected
            select_rad_nuclei_cbox->SetEnabled(kTRUE);
            particle_energy_entry->SetState(kFALSE);
            break;
    case 2: //gamma
            select_rad_nuclei_cbox->SetEnabled(kFALSE);
            particle_energy_entry->SetState(kTRUE);
            break;
    case 3: //proton
            select_rad_nuclei_cbox->SetEnabled(kFALSE);
            particle_energy_entry->SetState(kTRUE);
            break;
    
    }
    return;
}


void MyMainFrame::det_shape_selected(Int_t selected_item_id)
{
    //int det_shape_int = select_det_shape_cbox->GetSelected();
    switch(selected_item_id)
    {
    case 1: //cout << "Det shape cylinder" << endl;
            det_length_label->SetText("Detector length(cm)");
            det_inner_radius_label->SetText("Detector inner radius(cm)");
            det_outer_radius_label->SetText("Detector outer radius(cm)");
            break;
    case 2: //cout << "Det shape box" << endl;
            det_length_label->SetText("Detector length(cm)");
            det_inner_radius_label->SetText("Detector breadth(cm)");
            det_outer_radius_label->SetText("Detector height(cm)");
            det_inner_radius_entry->SetNumber(1);
            break;
    }
    return;
}

void MyMainFrame::check_geant4_button_clicked()
{   
    TString geant4_version = gSystem->GetFromPipe("geant4-config --version");
    
    if(geant4_version == "")
     {
       cout << "\033[31m"<<"Cannot find Geant4. Please source geant4.sh before running geant4_gui."<<"\033[0m"<< endl;
       return;         //red
     }
     else 
     {
        cout << "\033[32m"<<"Found Geant4 version " << geant4_version << " Click on Run CMAKE to proceed."<<"\033[0m" << endl;
     }                //green
     return;
}

void MyMainFrame::al_cover_button_clicked()
{
   if (al_cover_ON_button->GetState() == kButtonDown)
       { 
         al_cover_status_string = "al_cover_ON";
         al_thickness_entry->SetState(kTRUE); // Enable
         al_gap_entry->SetState(kTRUE);
        }    
    else if (al_cover_OFF_button->GetState() == kButtonDown)
        {
          al_cover_status_string = "al_cover_OFF";
          al_thickness_entry->SetState(kFALSE); // Disable
          al_gap_entry->SetState(kFALSE);
        } 
}

void MyMainFrame::clear_build_button_clicked()
{             
    //text_output->AddLine("Clearing contents of the build folder for a clean start."); update_text_output();
    
    //TString clear_build_command = "bash -c 'cd "+pwd_path+"/geant4/build && rm -rf * >> ../../log.txt 2>&1'";   
   // TString clear_build_command = "cd "+pwd_path+"/geant4/build && rm -rf *";   
    TString clear_build_command = "cd geant4/build && rm -rf *";   
    
    gSystem->GetFromPipe(clear_build_command);// > to rewrite log file
    cout << "\033[32m" << "Build folder cleared successfully. Click on Run CMAKE to proceed." << "\033[0m"  << endl;
        
}

void MyMainFrame::cmake_button_clicked()
{             
    //label->SetText("Working...");

    cout << "\033[33m" << "Running CMAKE..." << "\033[0m" << endl;
    
    TString cmake_command = "cd geant4/build && cmake ../source";   
    
    int cmake_status_int = gSystem->Exec(cmake_command);
    if(cmake_status_int != 0)
     {
       cout << "\033[31m" << "Error: CMAKE failed." << "\033[0m" << endl;
       label->SetText("");
        return;
     }
     else 
     {
       cout << "\033[32m" << "CMAKE completed successfully. Click on Run MAKE to proceed." << "\033[0m" << endl;
     }
    label->SetText("");
    return;
     
}


//2>&1 is a shell redirection operator. It redirects stderr (error output, file descriptor 2) to
//stdout (standard output, file descriptor 1) so that both standard output and error messages appear in the same stream.
        
void MyMainFrame::make_button_clicked()
{  
    label->SetText("Working...");
    
    int no_of_threads_int = no_of_threads_entry->GetNumber();
    no_of_threads_string = to_string(no_of_threads_int);
    
    cout << "\033[33m" << "Running MAKE using " << no_of_threads_int << " cores..." << "\033[0m" << endl;
    
    TString make_command = "cd geant4/build && make -j"+no_of_events_string;   
    
    int make_status_int = gSystem->Exec(make_command);// >> append to log file
    if( make_status_int != 0)
     {
       cout << "\033[31m" << "Error: MAKE failed." << "\033[0m" << endl;
       label->SetText("");
        return;
     }
     else 
     {
       cout << "\033[32m" << "MAKE completed successfully. Click on Run Simulation to proceed." << "\033[0m" << endl;
     }
    label->SetText("");
    return;
}


void MyMainFrame::run_sim_button_clicked()
{  
  //  make_button->SetEnabled(kFALSE);
  // cmake_button->SetEnabled(kFALSE);
   
   gSystem->Exec("cd geant4/build && rm -rf *.root");

   label->SetText("Working...");
   
   no_of_events_int = no_of_events_entry->GetNumber();
   no_of_events_string = to_string(no_of_events_int);
   cout << "No of events: " << no_of_events_int << endl;

   if(no_of_events_int > 100)
   {
        cout << "\033[33m" << "No of events " << no_of_events_int << " is more than 100..." << "\033[0m" <<endl;
        cout << "\033[33m" << "Switching OFF visualisation..." << "\033[0m" <<endl;
        vis_mode_OFF_button->SetState(kButtonDown); // Marks it as selected
        vis_mode_ON_button->SetState(kButtonUp); // Marks it as unselected
   }
   
    if(vis_mode_ON_button->GetState() == kButtonDown) //kButtonDown means button is pressed
       {
           cout << "\033[33m" << "Visualisation ON..." << "\033[0m" << endl;
           vis_mode_string = " vis_mode_on ";
       }
    else if(vis_mode_OFF_button->GetState() == kButtonDown)
            {
                cout << "\033[33m" << "Visualisation OFF..." << "\033[0m" << endl;
                vis_mode_string = " vis_mode_off ";
            }

   rad_source_int = select_rad_source_cbox->GetSelected();
   switch(rad_source_int)
   {
        case 1: cout << "\033[33m" << "Selected radioactive nuclei " << "\033[0m" << endl;
           rad_source_string = "rad_nuclei";  break;
        case 2: cout << "\033[33m" << "Selected particle: Gamma " << "\033[0m" << endl;
           rad_source_string = "rad_gamma";  break;
        case 3: cout << "\033[33m" << "Selected particle: Proton " << "\033[0m" << endl;
           rad_source_string = "rad_proton";  break;
          
   }

   if(rad_source_string=="rad_nuclei")
   {
        rad_nuclei_int = select_rad_nuclei_cbox->GetSelected();
        switch(rad_nuclei_int)
        {
            case 1: cout << "\033[33m" << "Selected radiative nuclei: Cs137" << "\033[0m" << endl;
                    rad_source_data_string = " Cs137 ";  break;
            case 2: cout << "\033[33m" << "Selected radiative nuclei: Co60" << "\033[0m" << endl;
                    rad_source_data_string = " Co60 ";  break;
            case 3: cout << "\033[33m" << "Selected radiative nuclei: Na22" << "\033[0m" << endl;
                    rad_source_data_string = " Na22 ";  break;
            case 4: cout << "\033[33m" << "Selected radiative nuclei: Ba133" << "\033[0m" << endl;
                    rad_source_data_string = " Ba133 ";  break;
        }
   }
   else if(rad_source_string=="rad_gamma")
   {
        rad_particle_energy_double = particle_energy_entry->GetNumber();
        rad_source_data_string = to_string(rad_particle_energy_double);  
   }
   else if(rad_source_string=="rad_proton")
   {
        rad_particle_energy_double = particle_energy_entry->GetNumber();
        rad_source_data_string = to_string(rad_particle_energy_double);  
   }

   det_shape_int = select_det_shape_cbox->GetSelected();
   
   switch(det_shape_int)
   {
   case 1: cout << "\033[33m" << "Selected detector shape: Cylinder" << "\033[0m" << endl;
           det_shape_string = " cylinder ";      break;
   case 2: cout << "\033[33m" << "Selected detector shape: Box" << "\033[0m" << endl;
           det_shape_string = " box ";      break;
   }

  
  // cout << "Det shape int: " << det_shape_int << endl;
  
   
   det_inner_radius_double = det_inner_radius_entry->GetNumber();
   det_inner_radius_string = to_string(det_inner_radius_double);
   
   det_outer_radius_double = det_outer_radius_entry->GetNumber();
   det_outer_radius_string = to_string(det_outer_radius_double);
   
   det_length_double = det_length_entry->GetNumber();
   det_length_string = to_string(det_length_double);
   
    if(al_cover_status_string == "al_cover_ON")
    {
        al_thickness_double = al_thickness_entry->GetNumber();
        al_thickness_string = to_string(al_thickness_double);
   
        al_gap_double = al_gap_entry->GetNumber();
        al_gap_string = to_string(al_gap_double);
    }
    else if (al_cover_status_string == "al_cover_OFF")
    {
        al_thickness_double = 0.0;
        al_thickness_string = to_string(al_thickness_double);
   
        al_gap_double = 0.0;
        al_gap_string = to_string(al_gap_double);
    }
   
   det_source_dis_double = det_source_dis_entry->GetNumber();
   det_source_dis_string = to_string(det_source_dis_double);
   
   if(    select_det_shape_cbox->GetSelected() == 1 
       && det_inner_radius_double >= det_outer_radius_double) 
   {
    cout << "\033[31m" << "Detector inner radius should be less than outer radius..." << "\033[0m" << endl;
    label->SetText("");
    return;  
   }  

   det_mat_int = select_det_mat_cbox->GetSelected();
   
   switch(det_mat_int)
   {
   case 1: cout << "\033[33m" << "Selected material: NaI" << "\033[0m" << endl;
           det_mat_string = " NaI "; break;
   case 2: cout << "\033[33m" << "Selected material: LaBr3" << "\033[0m" << endl;
           det_mat_string = " LaBr3 "; break;
   case 3: cout << "\033[33m" << "Selected material: CeBr3" << "\033[0m" << endl;
           det_mat_string = " CeBr3 "; break;
   case 4: cout << "\033[33m" << "Selected material: HPGe" << "\033[0m" << endl;
           det_mat_string = " HPGe "; break;
   case 5: cout << "\033[33m" << "Selected material: BGO" << "\033[0m" << endl;
           det_mat_string = " BGO "; break;
   }

   //cout << "Det mat int: " << det_mat_int << endl;


   no_of_threads_int = no_of_threads_entry->GetNumber();
   no_of_threads_string = to_string(no_of_threads_int);
   cout << "\033[33m" << "No of threads used for simulations:" << no_of_threads_int << "\033[0m"  << endl;
   
   cout << "\033[33m" << "Now running simulation..." << "\033[0m" << endl;
   
   //text_output->AddLine("Running simulation..."); update_text_output();     
   
   // Construct a shell command using the extracted executable name
   TString exe_command = "cd geant4/build && ./sim " + vis_mode_string
                         + no_of_threads_string + " "
                         + no_of_events_string + " "
                         + rad_source_string + " "
                         + rad_source_data_string + " "
                         + det_shape_string + " "
                         + det_inner_radius_string + " "
                         + det_outer_radius_string + " "
                         + det_source_dis_string + " "
                         + det_length_string + " "
                         + al_cover_status_string + " "
                         + al_thickness_string + " "
                         + al_gap_string + " "
                         + det_mat_string;
                         //+ " 2>&1 >> ../../log.txt
                         //+ " ' ";
                         // + " ' & ";
   
   cout << "\033[33m" << "Command to be executed: " << exe_command << "\033[0m" << endl;
   
   // Execute the command
   int sim_status = gSystem->Exec(exe_command);
   
   // Check execution result
  // cout << "Execution returned: " << sim_status << endl;
   
  // cout << "Merging ROOT files " << endl;
  // gSystem->Exec("bash -c 'cd "+pwd_path+"/geant4/build && hadd -f output.root output_t*.root' ");
   // -f flag to overwrite the merged output file
  // cout << "ROOT files merged to output.root" << endl;

   if (sim_status != 0)
    {
       //text_output->AddLine("Error: Simulation failed..."); update_text_output();
       cout << "\033[31m" << "ERROR: Simulation failed..." << "\033[0m" << endl;
       
       TString exe_command_2 = "cd /geant4/build && ./sim 2>&1";
       
       TString sim_output = gSystem->GetFromPipe(exe_command_2);
       // Convert TString to string
          string sim_output_cpp = string(sim_output.Data());

       cout << "Execution error returned: " << sim_output << endl;
        // String to search for
        string search_string = "error while loading shared libraries:";

       // Check if the string exists in the output
       if (sim_output_cpp.find(search_string) != string::npos)
         {
             cout << "\033[31m" << "ERROR: couldnt find GEANT4... Source geant4.sh file..." << "\033[0m" << endl;
             label->SetText("ERROR!");
             return;
         }
       label->SetText("");
       return;
    }
    else 
    {
       cout << "\033[33m" << "Simulation ran successfully..." << "\033[0m" << endl;
    }
    //text_output->AddLine("Run successful"); update_text_output();
    label->SetText("");

  //  make_button->SetEnabled(kTRUE);
  // cmake_button->SetEnabled(kTRUE);
   return;
}

void MyMainFrame::plot_spec_button_clicked()
{
   cout << "Checking root files..."<< endl;
   TString output_t0_root_file_exists = gSystem->GetFromPipe("cd "+pwd_path+"/geant4/build && ls | grep -x 'output_t0.root'");
    if (!output_t0_root_file_exists.IsNull())
    {
        cout << "Files found for merging! Now merging files..." << endl;
        
       // TString remove_root_files_command = "cd "+pwd_path+"/geant4/build && rm -rf output.root";   
       // int remove_root_files_status = gSystem->Exec(remove_root_files_command);
       // cout << "Removed previous root file." << endl;
        
        gSystem->Exec("bash -c 'cd "+pwd_path+"/geant4/build && hadd -fk404 output.root output_t*.root' ");
        // -f flag to overwrite the merged output file, for ZSTD compression(4), level 4
        cout << "ROOT files merged to output.root" << endl;
        
       TString remove_root_files_command = "cd "+pwd_path+"/geant4/build && rm -rf output_t*.root";   
       int remove_root_files_status = gSystem->Exec(remove_root_files_command);
        cout << "Removed files used for merging." << endl;
    } 
    else
    {
     cout << "No files found for merging." << endl;
    }
   
   cout << "Now plotting spectrum..." << endl;
   f1 = new TFile("geant4/build/output.root","READ");
   TCanvas* c1 = new TCanvas("c1");  
   c1->ToggleEventStatus();  
   TTree* t1 = (TTree*)f1->Get("Scoring");
   h1 = new TH1D("h1", "hist", 3000, 0.0, 3.0);
   //t1->Draw("fEdep>>h1","","");
   t1->Draw("fEdep>>h1");
   gPad->SetLogy(); 
   TTree* t2 = (TTree*)f1->Get("simulationInfo");
   t2->GetEntry(0);
   no_of_events_int = (int)t2->GetLeaf("fnoOfEvents")->GetValue();
   cout<<"no_of_events_int: "<<no_of_events_int<<endl;
  
   return;
}

void MyMainFrame::get_counts_button_clicked()
{
   //TFile* f1 = new TFile("geant4/build/output.root","READ");
   TTree* t2 = (TTree*)f1->Get("simulationInfo");
   t2->GetEntry(0);
   no_of_events_int = (int)t2->GetLeaf("fnoOfEvents")->GetValue();
   cout<<"no_of_events_int: "<<no_of_events_int<<endl;
   
   //rad_source_string = to_string(t2->GetLeaf("fradSource")->GetValue());
   rad_source_string = string((const char*)t2->GetLeaf("fradSource")->GetValuePointer());
   cout<<"rad_source_string "<<rad_source_string<<endl;

   int bin_number = get_counts_entry->GetNumber();
   int counts = h1->GetBinContent(bin_number);
   cout << "Counts at bin number " << bin_number << " : " << counts << endl;
   
   return;
}

void MyMainFrame::stop_sim_button_clicked()
{
   gSystem->Exec("pkill -f ./sim");
   cout << "Simulation stopped...\n";
   return;
}

void MyMainFrame::exit_button_clicked()
{ 
    cout << "Closing application...\n";
    gApplication->Terminate(0); // Gracefully exit the application
}

// Properly handle window close
void MyMainFrame::CloseWindow() {
    cout << "Closing application...\n";
    gApplication->Terminate(0);  // Stops the ROOT event loop
}

int geant4_gui() 
{

    TApplication app("ROOT Application", 0, nullptr);
    //0: Represents the argc parameter (argument count). Since no command-line arguments are being passed, this value is set to 0.
    //nullptr: Represents the argv parameter (argument vector). Since there are no command-line arguments, it is set to nullptr (null pointer).
   
    MyMainFrame *mainFrame = new MyMainFrame(gClient->GetRoot(), 700, 700); // Specifies the width and height of the MyMainFrame window in pixels.
    mainFrame->pwd_path = gSystem->pwd();
   // gSystem->Exec(" > log.txt");
    app.Run();

    // Delete main frame after application ends
    delete mainFrame;
    return 0;
}
