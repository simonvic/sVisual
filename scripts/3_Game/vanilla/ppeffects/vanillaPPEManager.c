
//temp ifdef so the workbench won't complain
#ifdef S_FRAMEWORK
modded class PPEManager{
		
	override void Init(){
		super.Init();
		GetGame().GetUpdateQueue(CALL_CATEGORY_GUI).Remove(this.Update);
	}
	
}
#endif