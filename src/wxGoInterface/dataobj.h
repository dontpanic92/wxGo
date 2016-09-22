#ifndef _WX_DATAOBJ_H_BASE_
#define _WX_DATAOBJ_H_BASE_
#include "wx/defs.h"
#if wxUSE_DATAOBJ
#include "wx/string.h"
#include "wx/bitmap.h"
#include "wx/list.h"
#include "wx/arrstr.h"
#if defined(__WXMSW__)
    #include "wx/msw/ole/dataform.h"
#elif defined(__WXMOTIF__)
    #include "wx/motif/dataform.h"
#elif defined(__WXGTK20__)
    #include "wx/gtk/dataform.h"
#elif defined(__WXGTK__)
    #include "wx/gtk1/dataform.h"
#elif defined(__WXX11__)
    #include "wx/x11/dataform.h"
#elif defined(__WXMAC__)
    #include "wx/osx/dataform.h"
#elif defined(__WXQT__)
    #include "wx/qt/dataform.h"
#endif
extern WXDLLIMPEXP_CORE const wxDataFormat& wxFormatInvalid;
class WXDLLIMPEXP_CORE wxDataObjectBase
{
public:
    enum Direction
    {
        Get  = 0x01,    
        Set  = 0x02,    
        Both = 0x03     
    };
    virtual ~wxDataObjectBase();
    virtual wxDataFormat GetPreferredFormat(Direction dir = Get) const = 0;
    virtual size_t GetFormatCount(Direction dir = Get) const = 0;
    virtual void GetAllFormats(wxDataFormat *formats,
                               Direction dir = Get) const = 0;
    virtual size_t GetDataSize(const wxDataFormat& format) const = 0;
    virtual bool GetDataHere(const wxDataFormat& format, void *buf) const = 0;
    virtual bool SetData(const wxDataFormat& WXUNUSED(format),
                         size_t WXUNUSED(len), const void * WXUNUSED(buf))
    {
        return false;
    }
    bool IsSupported(const wxDataFormat& format, Direction dir = Get) const;
};
#if defined(__WXMSW__)
    #include "wx/msw/ole/dataobj.h"
#elif defined(__WXMOTIF__)
    #include "wx/motif/dataobj.h"
#elif defined(__WXX11__)
    #include "wx/x11/dataobj.h"
#elif defined(__WXGTK20__)
    #include "wx/gtk/dataobj.h"
#elif defined(__WXGTK__)
    #include "wx/gtk1/dataobj.h"
#elif defined(__WXMAC__)
    #include "wx/osx/dataobj.h"
#elif defined(__WXQT__)
    #include "wx/qt/dataobj.h"
#endif
class WXDLLIMPEXP_CORE wxDataObjectSimple : public wxDataObject
{
public:
    wxDataObjectSimple(const wxDataFormat& format = wxFormatInvalid)
        : m_format(format)
        {
        }
    const wxDataFormat& GetFormat() const { return m_format; }
    void SetFormat(const wxDataFormat& format) { m_format = format; }
    virtual size_t GetDataSize() const
        { return 0; }
    virtual bool GetDataHere(void *WXUNUSED(buf)) const
        { return false; }
    virtual bool SetData(size_t WXUNUSED(len), const void *WXUNUSED(buf))
        { return false; }
    virtual wxDataFormat GetPreferredFormat(wxDataObjectBase::Direction WXUNUSED(dir) = Get) const wxOVERRIDE
        { return m_format; }
    virtual size_t GetFormatCount(wxDataObjectBase::Direction WXUNUSED(dir) = Get) const wxOVERRIDE
        { return 1; }
    virtual void GetAllFormats(wxDataFormat *formats,
                               wxDataObjectBase::Direction WXUNUSED(dir) = Get) const wxOVERRIDE
        { *formats = m_format; }
    virtual size_t GetDataSize(const wxDataFormat& WXUNUSED(format)) const wxOVERRIDE
        { return GetDataSize(); }
    virtual bool GetDataHere(const wxDataFormat& WXUNUSED(format),
                             void *buf) const wxOVERRIDE
        { return GetDataHere(buf); }
    virtual bool SetData(const wxDataFormat& WXUNUSED(format),
                         size_t len, const void *buf) wxOVERRIDE
        { return SetData(len, buf); }
private:
    wxDataFormat m_format;
    wxDECLARE_NO_COPY_CLASS(wxDataObjectSimple);
};
WX_DECLARE_EXPORTED_LIST(wxDataObjectSimple, wxSimpleDataObjectList);
class WXDLLIMPEXP_CORE wxDataObjectComposite : public wxDataObject
{
public:
    wxDataObjectComposite();
    virtual ~wxDataObjectComposite();
    void Add(wxDataObjectSimple *dataObject, bool preferred = false);
    wxDataFormat GetReceivedFormat() const;
    wxDataObjectSimple *GetObject(const wxDataFormat& format,
                                  wxDataObjectBase::Direction dir = Get) const;
    virtual wxDataFormat GetPreferredFormat(wxDataObjectBase::Direction dir = Get) const wxOVERRIDE;
    virtual size_t GetFormatCount(wxDataObjectBase::Direction dir = Get) const wxOVERRIDE;
    virtual void GetAllFormats(wxDataFormat *formats, wxDataObjectBase::Direction dir = Get) const wxOVERRIDE;
    virtual size_t GetDataSize(const wxDataFormat& format) const wxOVERRIDE;
    virtual bool GetDataHere(const wxDataFormat& format, void *buf) const wxOVERRIDE;
    virtual bool SetData(const wxDataFormat& format, size_t len, const void *buf) wxOVERRIDE;
#if defined(__WXMSW__)
    virtual const void* GetSizeFromBuffer( const void* buffer, size_t* size,
                                           const wxDataFormat& format );
    virtual void* SetSizeInBuffer( void* buffer, size_t size,
                                   const wxDataFormat& format );
    virtual size_t GetBufferOffset( const wxDataFormat& format );
#endif
private:
    wxSimpleDataObjectList m_dataObjects;
    size_t m_preferred;
    wxDataFormat m_receivedFormat;
    wxDECLARE_NO_COPY_CLASS(wxDataObjectComposite);
};
#if wxUSE_UNICODE
    #if defined(__WXGTK20__) || defined(__WXX11__)
        #define wxNEEDS_UTF8_FOR_TEXT_DATAOBJ
    #elif defined(__WXMAC__)
        #define wxNEEDS_UTF16_FOR_TEXT_DATAOBJ
    #endif
#endif 
class WXDLLIMPEXP_CORE wxHTMLDataObject : public wxDataObjectSimple
{
public:
    wxHTMLDataObject(const wxString& html = wxEmptyString)
        : wxDataObjectSimple(wxDF_HTML),
          m_html(html)
        {
        }
    virtual size_t GetLength() const { return m_html.Len() + 1; }
    virtual wxString GetHTML() const { return m_html; }
    virtual void SetHTML(const wxString& html) { m_html = html; }
    virtual size_t GetDataSize() const wxOVERRIDE;
    virtual bool GetDataHere(void *buf) const wxOVERRIDE;
    virtual bool SetData(size_t len, const void *buf) wxOVERRIDE;
    virtual size_t GetDataSize(const wxDataFormat&) const wxOVERRIDE
    {
        return GetDataSize();
    }
    virtual bool GetDataHere(const wxDataFormat&, void *buf) const wxOVERRIDE
    {
        return GetDataHere(buf);
    }
    virtual bool SetData(const wxDataFormat&, size_t len, const void *buf) wxOVERRIDE
    {
        return SetData(len, buf);
    }
private:
    wxString m_html;
};
class WXDLLIMPEXP_CORE wxTextDataObject : public wxDataObjectSimple
{
public:
    wxTextDataObject(const wxString& text = wxEmptyString)
        : wxDataObjectSimple(
#if wxUSE_UNICODE
                             wxDF_UNICODETEXT
#else
                             wxDF_TEXT
#endif
                            ),
          m_text(text)
        {
        }
    virtual size_t GetTextLength() const { return m_text.Len() + 1; }
    virtual wxString GetText() const { return m_text; }
    virtual void SetText(const wxString& text) { m_text = text; }
#if defined(wxNEEDS_UTF8_FOR_TEXT_DATAOBJ) || defined(wxNEEDS_UTF16_FOR_TEXT_DATAOBJ)
    virtual size_t GetFormatCount(Direction WXUNUSED(dir) = Get) const wxOVERRIDE { return 2; }
    virtual void GetAllFormats(wxDataFormat *formats,
                               wxDataObjectBase::Direction WXUNUSED(dir) = Get) const wxOVERRIDE;
    virtual size_t GetDataSize() const wxOVERRIDE { return GetDataSize(GetPreferredFormat()); }
    virtual bool GetDataHere(void *buf) const wxOVERRIDE { return GetDataHere(GetPreferredFormat(), buf); }
    virtual bool SetData(size_t len, const void *buf) wxOVERRIDE { return SetData(GetPreferredFormat(), len, buf); }
    size_t GetDataSize(const wxDataFormat& format) const wxOVERRIDE;
    bool GetDataHere(const wxDataFormat& format, void *pBuf) const wxOVERRIDE;
    bool SetData(const wxDataFormat& format, size_t nLen, const void* pBuf) wxOVERRIDE;
#else 
    virtual size_t GetDataSize() const;
    virtual bool GetDataHere(void *buf) const;
    virtual bool SetData(size_t len, const void *buf);
    virtual size_t GetDataSize(const wxDataFormat&) const
    {
        return GetDataSize();
    }
    virtual bool GetDataHere(const wxDataFormat&, void *buf) const
    {
        return GetDataHere(buf);
    }
    virtual bool SetData(const wxDataFormat&, size_t len, const void *buf)
    {
        return SetData(len, buf);
    }
#endif 
private:
    wxString m_text;
    wxDECLARE_NO_COPY_CLASS(wxTextDataObject);
};
class WXDLLIMPEXP_CORE wxBitmapDataObjectBase : public wxDataObjectSimple
{
public:
    wxBitmapDataObjectBase(const wxBitmap& bitmap = wxNullBitmap)
        : wxDataObjectSimple(wxDF_BITMAP), m_bitmap(bitmap)
        {
        }
    virtual wxBitmap GetBitmap() const { return m_bitmap; }
    virtual void SetBitmap(const wxBitmap& bitmap) { m_bitmap = bitmap; }
protected:
    wxBitmap m_bitmap;
    wxDECLARE_NO_COPY_CLASS(wxBitmapDataObjectBase);
};
class WXDLLIMPEXP_CORE wxFileDataObjectBase : public wxDataObjectSimple
{
public:
    wxFileDataObjectBase() : wxDataObjectSimple(wxDF_FILENAME) { }
    const wxArrayString& GetFilenames() const { return m_filenames; }
protected:
    wxArrayString m_filenames;
    wxDECLARE_NO_COPY_CLASS(wxFileDataObjectBase);
};
class WXDLLIMPEXP_CORE wxCustomDataObject : public wxDataObjectSimple
{
public:
    wxCustomDataObject(const wxDataFormat& format = wxFormatInvalid);
    virtual ~wxCustomDataObject();
    void TakeData(size_t size, void *data);
    virtual void *Alloc(size_t size);
    virtual void Free();
    virtual size_t GetSize() const { return m_size; }
    virtual void *GetData() const { return m_data; }
    virtual size_t GetDataSize() const wxOVERRIDE;
    virtual bool GetDataHere(void *buf) const wxOVERRIDE;
    virtual bool SetData(size_t size, const void *buf) wxOVERRIDE;
    virtual size_t GetDataSize(const wxDataFormat&) const wxOVERRIDE
    {
        return GetDataSize();
    }
    virtual bool GetDataHere(const wxDataFormat&, void *buf) const wxOVERRIDE
    {
        return GetDataHere(buf);
    }
    virtual bool SetData(const wxDataFormat&, size_t len, const void *buf) wxOVERRIDE
    {
        return SetData(len, buf);
    }
private:
    size_t m_size;
    void  *m_data;
    wxDECLARE_NO_COPY_CLASS(wxCustomDataObject);
};
#if defined(__WXMSW__)
    #include "wx/msw/ole/dataobj2.h"
#elif defined(__WXGTK20__)
    #include "wx/gtk/dataobj2.h"
#else
    #if defined(__WXGTK__)
        #include "wx/gtk1/dataobj2.h"
    #elif defined(__WXX11__)
        #include "wx/x11/dataobj2.h"
    #elif defined(__WXMOTIF__)
        #include "wx/motif/dataobj2.h"
    #elif defined(__WXMAC__)
        #include "wx/osx/dataobj2.h"
    #elif defined(__WXQT__)
        #include "wx/qt/dataobj2.h"
    #endif
    class WXDLLIMPEXP_CORE wxURLDataObject : public wxTextDataObject
    {
    public:
        wxURLDataObject(const wxString& url = wxEmptyString)
            : wxTextDataObject(url)
        {
        }
        wxString GetURL() const { return GetText(); }
        void SetURL(const wxString& url) { SetText(url); }
    };
#endif
#endif 
#endif 