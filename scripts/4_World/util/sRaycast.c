//@todo managed?
class SRaycast {
	
	protected vector m_begPos;
	protected vector m_endPos;
	
	protected float m_radius;
	protected int m_intersectionType;
	protected CollisionFlags m_collisionFlags;
	protected bool m_sorted;
	protected bool m_groundOnly;
	protected ref set<Object> m_ignoredObjects = new set<Object>;	

	protected vector m_contactPos;
	protected vector m_contactDir;
	protected int m_contactComponent;
	protected ref set<Object> m_hitObjects = new set<Object>;
		
	protected bool m_hasHit;
	void SRaycast(vector begPos, vector endPos, float radius, int intersectionType = ObjIntersectView, CollisionFlags collisionFlags = CollisionFlags.NEARESTCONTACT, bool sorted = false, bool groundOnly = false){
		m_begPos = begPos;
		m_endPos = endPos;
		m_radius = radius;
		m_intersectionType = intersectionType;
		m_collisionFlags = collisionFlags;
		m_sorted = sorted;
		m_groundOnly = groundOnly;
	}
	
	void launch(){
		m_hasHit = DayZPhysics.RaycastRV(m_begPos, m_endPos, m_contactPos, m_contactDir, m_contactComponent, m_hitObjects, m_ignoredObjects.Get(0), m_ignoredObjects.Get(1), m_sorted, m_groundOnly, m_intersectionType, m_radius, m_collisionFlags);
	}
	
	bool hasHit(){
		return m_hasHit;
	}
	
	vector getBegPos(){
		return m_begPos;
	}
	
	void setBegPos(vector begPos){
		m_begPos = begPos;
	}
	
	vector getEndPos(){
		return m_endPos;
	}
	
	void setEndPos(vector endPos){
		m_endPos = endPos;
	}
	
	float getRadius(){
		return m_radius;
	}
	
	void setRadius(float radius){
		m_radius = radius;
	}
	
	int getIntersectionType(){
		return m_intersectionType;
	}
	
	void setIntersectionType(int intersectionType){
		m_intersectionType = intersectionType;
	}
	
	CollisionFlags getCollisionFlags(){
		return m_collisionFlags;
	}
	
	void setCollisionFlags(CollisionFlags collisionFlags){
		m_collisionFlags = collisionFlags;
	}
	
	bool isSorted(){
		return m_sorted;
	}
	
	void setSorted(bool sorted){
		m_sorted = sorted;
	}
	
	bool isGroundOnly(){
		return m_groundOnly;
	}
	
	void setGroundOnly(bool groundOnly){
		m_groundOnly = groundOnly;
	}
	
	set<Object> getOjectsIgnored(){
		return m_ignoredObjects;
	}
	
	void addIgnoredObject(Object ignoredObject){
		m_ignoredObjects.Insert(ignoredObject);
	}
	
	void removeIgnoredObject(Object objectToRemove){
		m_ignoredObjects.Remove(m_ignoredObjects.Find(objectToRemove));
	}
	
	vector getContactPos(){
		return m_contactPos;
	}
	
	vector getContactDir(){
		return m_contactDir;
	}
	
	int getContactComponent(){
		return m_contactComponent;
	}
	
	set<Object> getOjectsHit(){
		return m_hitObjects;
	}
	
	
	
	
}