#pragma once
#include "Unique/StateMachine/State.h"

namespace Unique 
{
	template<typename T, typename Condition>
	class StateMachine
	{
	public:
		StateMachine(T* owner)
			: m_Owner(owner), m_CurrentState(nullptr) {}

		inline virtual void SetTransition(Condition condition, State<T, Condition>* toState) 
		{
			auto contains = m_Transitions.find(condition);
			if (contains == m_Transitions.end())
			{
				m_Transitions[condition] = toState;
				UQ_CORE_INFO("Create {0} State", ConditionToString(condition));
			}
			else
			{
				UQ_CORE_WARN("Already Created {0} State", ConditionToString(condition));
			}
		}

		inline virtual void ChangeState(Condition condition) 
		{
			if (m_CurrentState)
			{
				m_CurrentState->Exit(m_Owner);
			}
			auto contains = m_Transitions.find(condition);
			if (contains != m_Transitions.end())
			{
				if (m_CurrentState == contains->second)
				{
					UQ_CORE_WARN("Same State : {0}", ConditionToString(condition));
				}
				else
				{
					m_CurrentState = contains->second;
					UQ_CORE_INFO("Change to {0} State", ConditionToString(condition));
					m_CurrentState->Enter(m_Owner);

				}
			}
			else
			{
				UQ_CORE_WARN("Don't have {0} State", ConditionToString(condition));
			}
		}

		inline virtual void Update() 
		{
			if (m_CurrentState)
				m_CurrentState->Update(m_Owner);
		}

	private:
		virtual	std::string ConditionToString(Condition condition) 
		{
			return "Unknown condition";
		}
		T* m_Owner;
		State<T,Condition>* m_CurrentState;
		std::unordered_map<Condition, State<T, Condition>*> m_Transitions;
	};

}