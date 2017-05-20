#ifndef OBJECTFOURTUPLE_H
#define OBJECTFOURTUPLE_H


template<typename T>
class ObjectFourTuple
{
public:
    ObjectFourTuple(){}
    ~ObjectFourTuple(){}

public:
    //Set
    void SetNormalState(T normalState)
    {
        m_normalState = normalState;
    }

    void SetOverState(T overState)
    {
        m_overState = overState;
    }

    void SetPressState(T pressState)
    {
        m_pressState = pressState;
    }

    void SetDisableState(T disableState)
    {
        m_disableState = disableState;
    }
    void SetAllState(T state)
    {
       SetNormalState(state);
       SetOverState(state);
       SetPressState(state);
       SetDisableState(state);
    }

    //Get
    T GetNormalState()
    {
        return m_normalState;
    }
    T GetOverState()
    {
        return m_overState;
    }
    T GetPressState()
    {
        return m_pressState;
    }
    T GetDisableState()
    {
        return m_disableState;
    }

private:
    T m_normalState;
    T m_overState;
    T m_pressState;
    T m_disableState;
};

#endif // OBJECTFOURTUPLE_H
