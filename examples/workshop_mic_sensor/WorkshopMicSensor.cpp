//Sensor app file 

#include "WorkshopMicSensor.h"

REG_SERIALIZABLE( Microphone );
RTTI_IMPL(Microphone, ISensor);

void Microphone::Serialize(Json::Value & json)
{
	ISensor::Serialize( json );

	json["m_RecordingHZ"] = m_RecordingHZ;
	json["m_RecordingBits"] = m_RecordingBits;
	json["m_RecordingChannels"] = m_RecordingChannels;
}	

void Microphone::Deserialize(const Json::Value & json)
{
	ISensor::Deserialize( json );
	
	if( json.isMember("m_RecordingHZ") )
		m_RecordingHZ = json["m_RecordingHZ"].asInt();
	if( json.isMember("m_RecordingBits") )
		m_RecordingBits = json["m_RecordingBits"].asInt();
	if( json.isMember("m_RecordingChannels") )
		m_RecordingChannels = json["m_RecordingChannels"].asInt();

	m_BinaryType = StringUtil::Format("audio/L%u;rate=%uchannels=%u",m_RecordingBits,
m_RecordingHZ, m_RecordingChannels);
}

bool Microphone::OnStart()
{
	Log::Warning( "Microphone", "Microphone is not implemented.");
	return true;
}

bool Microphone::OnStop()
{
	return true;
}

void Microphone::OnPause()
{}

void Microphone::OnResume()
{}

