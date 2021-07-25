//if we had interfaces... right? :(
// I like to call this the "pseudo-interface pattern" :)

enum eSAnimableState {
	PLAYING = 0,
	PAUSED,
	STOPPED	
}

class SAnimable {

	protected eSAnimableState m_animationState = eSAnimableState.STOPPED;
	protected float m_time;
	
	void animate(float deltaTime){
		if(!isPlaying()) return;
		
		m_time += deltaTime;
		onAnimate(deltaTime);
	}
	
	void onStart();
	void onAnimate(float deltaTime);
	void onStop();
	void onPause();
	void onResume();
		
	/**
	* @brief Set the animation state to PLAYING and reset the time
	*/
	void start(){
		m_time = 0;
		setAnimationState(eSAnimableState.PLAYING);
		onStart();
	}
	
	/**
	* @brief Reset values to default and prepare to stop
	*/
	void stop(){
		setAnimationState(eSAnimableState.STOPPED);
		onStop();
	}
	
	/**
	* @brief Pause the animation from animating without resetting the time
	*/
	void pause(){
		setAnimationState(eSAnimableState.PAUSED);
		onPause();
	}
	
	/**
	* @brief Resume the animation
	*/
	void resume(){
		setAnimationState(eSAnimableState.PLAYING);
		onResume();
	}
	
	/**
	* @brief Get the time elapsed from the animation start
	* 	@return \p float - time elapsed
	*/
	float getTime(){
		return m_time;
	}
	
	bool isPlaying(){
		return m_animationState == eSAnimableState.PLAYING;
	}
	
	bool isPaused(){
		return m_animationState == eSAnimableState.PAUSED;
	}
	
	bool hasStopped(){
		return m_animationState == eSAnimableState.STOPPED;
	}
	
	eSAnimableState getAnimationState(){
		return m_animationState;
	}
	
	protected void setAnimationState(eSAnimableState state){
		m_animationState = state;
	}
}

class SAnimableTimed : SAnimable {
	
	protected float m_duration;
	
	void SAnimableTimed(float duration){
		m_duration = duration;
	}

	override void animate(float deltaTime){
		if( !isPlaying() ) {
			return; 
		}
		
		if(getTime() >= m_duration ) {
			stop();
			return;
		}
		super.animate(deltaTime);
	}
	
	/**
	* @brief Set the duration of the animation
	* 	@param duration \p float - animation duration (seconds)
	*/
	void setDuration(float duration){
		m_duration = duration;
	}
		
	/**
	* @brief Get the animation duration
	* 	@return \p float - animation duration (seconds)
	*/
	float getDuration() {
		return m_duration;
	}
		
	/**
	* @brief Get the time remaining to the completition
	* 	@return \p float - time remaining (seconds)
	*/
	float getRemaining() {
		return m_duration - m_time;
	}
	
}