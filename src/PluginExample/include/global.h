#ifndef GLOBAL_H
#define GLOBAL_H

namespace params
{
    enum Operation {
        NOOPERATION,
        GETALLWINDOWS,
        GETALLCONTROLS,
        SETCONTROLTEXT,
        GETCONTROLINFO,
        RUNPROCESS
    };

    enum ControlType {
        EDIT,
        BUTTON,
        COMBOBOX
    };
}

//------------------------------------------------------------------------------------

namespace datatypes
{
    class AbstractData
    {
    public:
        virtual ~AbstractData()
        {
        }

        virtual params::Operation type() const = 0;
    };

    class AbstractIndexData : public AbstractData
    {
    public:
        AbstractIndexData(int index)
            : index_(index)
        {
        }

        int index() const
        {
            return index_;
        }

    private:
        int index_;
    };

    class ControlInfoData : public AbstractData
    {
    public:
        ControlInfoData(const QString& controlInfo)
            : controlInfo_(controlInfo)
        {
        }

        const QString& controlInfo() const
        {
            return controlInfo_;
        }

        virtual params::Operation type() const
        {
            return params::GETCONTROLINFO;
        }

    private:
        QString controlInfo_;
    };

    class WindowData : public AbstractData
    {
    public:
        WindowData(QString windowName, QString windowClass)
            : windowName_(windowName)
            , windowClass_(windowClass)
        {
        }

        virtual params::Operation type() const
        {
            return params::GETALLWINDOWS;
        }

        const QString& windowName() const
        {
            return windowName_;
        }

        const QString& windowClass() const
        {
            return windowClass_;
        }

    private:
        QString windowName_;
        QString windowClass_;

    };

    class ControlData : public AbstractIndexData
    {
    public:
        ControlData(int controlIndex, QString controlText, QString controlClass)
            : AbstractIndexData(controlIndex)
            , controlText_(controlText)
            , controlClass_(controlClass)
        {
        }

        virtual params::Operation type() const
        {
            return params::GETALLCONTROLS;
        }

        const QString& controlText() const
        {
            return controlText_;
        }

        const QString& controlClass() const
        {
            return controlClass_;
        }

    private:
        QString controlText_;
        QString controlClass_;
    };
}

#endif // GLOBAL_H
