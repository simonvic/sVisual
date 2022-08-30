modded class PPEManager{
		
	override void Init() {
		super.Init();
		GetGame().GetUpdateQueue(CALL_CATEGORY_GUI).Remove(this.Update);
	}
	
}